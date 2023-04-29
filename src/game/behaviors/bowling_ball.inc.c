// bowling_ball.inc.c

extern const Trajectory wf_area_1_spline_balls_path_1[];
extern const Trajectory wf_area_1_spline_balls_path_2[];

extern const Trajectory bbh_area_1_spline_NurbsCurve[];
extern const Trajectory bbh_area_1_spline_NurbsCurve_l[];
extern const Trajectory bbh_area_1_spline_NurbsCurve_r[];
extern const Trajectory bbh_area_1_spline_NurbsCurve_001[];
extern const Trajectory bbh_area_1_spline_NurbsCurve_001_l[];
extern const Trajectory bbh_area_1_spline_NurbsCurve_001_r[];
extern const Trajectory bbh_area_1_spline_NurbsCurve_002[];

static const struct ObjectHitbox sBowlingBallHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 150,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

static Trajectory sThiHugeMetalBallTraj[] = {
    TRAJECTORY_POS(0, /*pos*/ -4786,   101, -2166),
    TRAJECTORY_POS(1, /*pos*/ -5000,    81, -2753),
    TRAJECTORY_POS(2, /*pos*/ -5040,    33, -3846),
    TRAJECTORY_POS(3, /*pos*/ -4966,    38, -4966),
    TRAJECTORY_POS(4, /*pos*/ -4013,  -259, -4893),
    TRAJECTORY_POS(5, /*pos*/ -2573, -1019, -4780),
    TRAJECTORY_POS(6, /*pos*/ -1053, -1399, -4806),
    TRAJECTORY_POS(7, /*pos*/   760, -1637, -4833),
    TRAJECTORY_POS(8, /*pos*/  2866, -2047, -4886),
    TRAJECTORY_POS(9, /*pos*/  3386, -6546, -4833),
    TRAJECTORY_END(),
};

static Trajectory sThiTinyMetalBallTraj[] = {
    TRAJECTORY_POS(0, /*pos*/ -1476,    29,  -680),
    TRAJECTORY_POS(1, /*pos*/ -1492,    14, -1072),
    TRAJECTORY_POS(2, /*pos*/ -1500,     3, -1331),
    TRAJECTORY_POS(3, /*pos*/ -1374,   -17, -1527),
    TRAJECTORY_POS(4, /*pos*/ -1178,   -83, -1496),
    TRAJECTORY_POS(5, /*pos*/  -292,  -424, -1425),
    TRAJECTORY_POS(6, /*pos*/   250,  -491, -1433),
    TRAJECTORY_POS(7, /*pos*/   862,  -613, -1449),
    TRAJECTORY_POS(8, /*pos*/  1058, -1960, -1449),
    TRAJECTORY_END(),
};

void bhv_bowling_ball_init(void) {
    o->oGravity = 5.5f;
    o->oFriction = 1.0f;
    o->oBuoyancy = 2.0f;
}

void bowling_ball_set_hitbox(void) {
    obj_set_hitbox(o, &sBowlingBallHitbox);

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->oInteractStatus = INT_STATUS_NONE;
    }
}

static const void* sTrajectories2[] = 
{
    bbh_area_1_spline_NurbsCurve_001, bbh_area_1_spline_NurbsCurve_001_l, bbh_area_1_spline_NurbsCurve_001, bbh_area_1_spline_NurbsCurve_001_r
};

static const void* sTrajectories3[] = 
{
    bbh_area_1_spline_NurbsCurve, bbh_area_1_spline_NurbsCurve_l, bbh_area_1_spline_NurbsCurve, bbh_area_1_spline_NurbsCurve_r
};

void bowling_ball_set_waypoints(void) {
    static int ballCounters[5] = { 0 };
    switch (o->oBehParams2ndByte) {
        case BBALL_BP_STYPE_BOB_UPPER:
            o->oPathedStartWaypoint = segmented_to_virtual(wf_area_1_spline_balls_path_1);
            break;

        case BBALL_BP_STYPE_TTM:
            o->oPathedStartWaypoint = segmented_to_virtual(wf_area_1_spline_balls_path_2);
            break;

        case BBALL_BP_STYPE_BOB_LOWER:
            o->oPathedStartWaypoint = segmented_to_virtual(bbh_area_1_spline_NurbsCurve_002);
            break;

        case BBALL_BP_STYPE_THI_LARGE:
            o->oPathedStartWaypoint = segmented_to_virtual(sTrajectories2[((++ballCounters[BBALL_BP_STYPE_THI_LARGE]) / 2) % 4]);
            break;

        case BBALL_BP_STYPE_THI_SMALL:
            o->oPathedStartWaypoint = segmented_to_virtual(sTrajectories3[((++ballCounters[BBALL_BP_STYPE_THI_SMALL]) / 2) % 4]);
            break;
    }
}

void bhv_bowling_ball_roll_loop(void) {
    bowling_ball_set_waypoints();
    s16 collisionFlags = object_step();

    s32 followStatus = cur_obj_follow_path();

    o->oBowlingBallTargetYaw = o->oPathedTargetYaw;
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oBowlingBallTargetYaw, 0x400);
    if (o->oForwardVel > 70.0f) {
        o->oForwardVel = 70.0f;
    }

    if (o->header.gfx.sharedChild != gLoadedGraphNodes[MODEL_RED_FLAME])
        bowling_ball_set_hitbox();

    if (followStatus == PATH_REACHED_END) {
        if (is_point_within_radius_of_mario(o->oPosX, o->oPosY, o->oPosZ, 7000)) {
            spawn_mist_particles();
            spawn_mist_particles_variable(0, 0, 92.0f);
        }

        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }

    if (o->header.gfx.sharedChild != gLoadedGraphNodes[MODEL_RED_FLAME])
    if ((collisionFlags & OBJ_COL_FLAG_GROUNDED) && (o->oVelY > 5.0f)) {
        cur_obj_play_sound_2(SOUND_GENERAL_QUIET_POUND1_LOWPRIO);
    }
}

void bhv_bowling_ball_initialize_loop(void) {
    bowling_ball_set_waypoints();

    cur_obj_follow_path();

    o->oMoveAngleYaw = o->oPathedTargetYaw;

    switch (o->oBehParams2ndByte) {
        case BBALL_BP_STYPE_BOB_UPPER:
            o->oForwardVel = 20.0f;
            break;

        case BBALL_BP_STYPE_TTM:
            o->oForwardVel = 10.0f;
            break;

        case BBALL_BP_STYPE_BOB_LOWER:
            o->oForwardVel = 30.0f;
            break;

        case BBALL_BP_STYPE_THI_LARGE:
            o->oForwardVel = 20.0f;
            break;

        case BBALL_BP_STYPE_THI_SMALL:
            o->oForwardVel = 30.0f;
            break;
    }
}

void bhv_bowling_ball_loop(void) {
    switch (o->oAction) {
        case BBALL_ACT_INITIALIZE:
            o->oAction = BBALL_ACT_ROLL;
            bhv_bowling_ball_initialize_loop();
            break;

        case BBALL_ACT_ROLL:
            bhv_bowling_ball_roll_loop();
            break;
    }

    if (o->oBehParams2ndByte != BBALL_BP_STYPE_THI_SMALL) {
        set_camera_shake_from_point(SHAKE_POS_BOWLING_BALL, o->oPosX, o->oPosY, o->oPosZ);
    }

    set_object_visibility(o, 4000);
}

void bhv_generic_bowling_ball_spawner_init(void) {
    switch (o->oBehParams2ndByte) {
        case BBALL_BP_STYPE_BOB_UPPER:
            o->oBBallSpawnerMaxSpawnDist = 7000.0f;
            o->oBBallSpawnerSpawnOdds = 1.0f;
            break;

        case BBALL_BP_STYPE_TTM:
            o->oBBallSpawnerMaxSpawnDist = 8000.0f;
            o->oBBallSpawnerSpawnOdds = 1.0f;
            break;

        case BBALL_BP_STYPE_BOB_LOWER:
            o->oBBallSpawnerMaxSpawnDist = 6000.0f;
            o->oBBallSpawnerSpawnOdds = 1.0f;
            break;
    }
}

void bhv_generic_bowling_ball_spawner_loop(void) {
    if (o->oTimer == 256) {
        o->oTimer = 0;
    }

    if (is_point_within_radius_of_mario(o->oPosX, o->oPosY, o->oPosZ, 1000)
        || o->oPosY < gMarioObject->header.gfx.pos[1]) {
        return;
    }

    if ((o->oTimer & o->oBBallSpawnerPeriodMinus1) == 0) { /* Modulus */
        //if (is_point_within_radius_of_mario(o->oPosX, o->oPosY, o->oPosZ, o->oBBallSpawnerMaxSpawnDist)) {
            struct Object *bowlingBall = spawn_object(o, MODEL_BOWLING_BALL, bhvBowlingBall);
            bowlingBall->oBehParams2ndByte = o->oBehParams2ndByte;
        //}
    }
}

void bhv_thi_bowling_ball_spawner_loop(void) {
    if (o->oTimer == 256) {
        o->oTimer = 0;
    }

    if (is_point_within_radius_of_mario(o->oPosX, o->oPosY, o->oPosZ, 800)
        || o->oPosY < gMarioObject->header.gfx.pos[1]) {
        return;
    }

    if ((o->oTimer % 33) == 0) {
        if (is_point_within_radius_of_mario(o->oPosX, o->oPosY, o->oPosZ, 12000)
            && (s32)(random_float() * 1.5) == 0) {
            struct Object *bowlingBall = spawn_object(o, MODEL_RED_FLAME, bhvBowlingFire);
            bowlingBall->oBehParams2ndByte = o->oBehParams2ndByte;
        }
    }
}

void bhv_bob_pit_bowling_ball_init(void) {
    o->oGravity = 12.0f;
    o->oFriction = 1.0f;
    o->oBuoyancy = 2.0f;
}

void bhv_bob_pit_bowling_ball_loop(void) {
    object_step();

    if ((o->oFloor != NULL) && (o->oFloor->normal.x == 0) && (o->oFloor->normal.z == 0)) {
        o->oForwardVel = 28.0f;
    }
    bowling_ball_set_hitbox();
    set_camera_shake_from_point(SHAKE_POS_BOWLING_BALL, o->oPosX, o->oPosY, o->oPosZ);
    cur_obj_play_sound_1(SOUND_ENV_BOWLING_BALL_ROLL);
    set_object_visibility(o, 3000);
}

void bhv_free_bowling_ball_init(void) {
    o->oGravity = 5.5f;
    o->oFriction = 1.0f;
    o->oBuoyancy = 2.0f;
    vec3f_copy(&o->oHomeVec, &o->oPosVec);
    o->oForwardVel = 0;
    o->oMoveAngleYaw = 0;
}

void bhv_free_bowling_ball_roll_loop(void) {
    object_step();

    bowling_ball_set_hitbox();

    if (o->oForwardVel > 10.0f) {
        set_camera_shake_from_point(SHAKE_POS_BOWLING_BALL, o->oPosX, o->oPosY, o->oPosZ);
        cur_obj_play_sound_1(SOUND_ENV_BOWLING_BALL_ROLL);
    }

    /* Always false, commented out to suppress compiler warnings. */
    // if ((collisionFlags & OBJ_COL_FLAG_GROUNDED) && !(collisionFlags & OBJ_COL_FLAGS_LANDED)) {
    //     cur_obj_play_sound_2(SOUND_GENERAL_QUIET_POUND1_LOWPRIO);
    // }

    if (!is_point_within_radius_of_mario(o->oPosX, o->oPosY, o->oPosZ, 6000)) {
        o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
        cur_obj_become_intangible();
        vec3f_copy(&o->oPosVec, &o->oHomeVec);
        bhv_free_bowling_ball_init();
        o->oAction = FREE_BBALL_ACT_RESET;
    }
}

void bhv_free_bowling_ball_loop(void) {
    o->oGravity = 5.5f;

    switch (o->oAction) {
        case FREE_BBALL_ACT_IDLE:
            if (is_point_within_radius_of_mario(o->oPosX, o->oPosY, o->oPosZ, 3000)) {
                o->oAction = FREE_BBALL_ACT_ROLL;
                o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
                cur_obj_become_tangible();
            }
            break;

        case FREE_BBALL_ACT_ROLL:
            bhv_free_bowling_ball_roll_loop();
            break;

        case FREE_BBALL_ACT_RESET:
            if (is_point_within_radius_of_mario(o->oPosX, o->oPosY, o->oPosZ, 5000)) {
                o->oAction = FREE_BBALL_ACT_IDLE;
            }
            break;
    }
}
