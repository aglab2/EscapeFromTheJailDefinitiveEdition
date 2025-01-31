// controllable_platform.inc.c

s8 sControllablePlatformDirectionState = 0;

void controllable_platform_act_1(void) {
    o->oParentRelativePosY -= 4.0f;
    if (o->oParentRelativePosY < 41.0f) {
        o->oParentRelativePosY = 41.0f;
        o->oAction = 2;
    }
}

void controllable_platform_act_2(void) {
    if (o->oBehParams2ndByte == sControllablePlatformDirectionState) {
        return;
    }

    o->oParentRelativePosY += 4.0f;
    if (o->oParentRelativePosY > 51.0f) {
        o->oParentRelativePosY = 51.0f;
        o->oAction = 0;
    }
}

void bhv_controllable_platform_sub_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer < 30) {
                break;
            }

            if (gMarioObject->platform == o) {
                sControllablePlatformDirectionState = o->oBehParams2ndByte;
                o->parentObj->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
                o->oAction = 1;
                cur_obj_play_sound_2(SOUND_GENERAL_MOVING_PLATFORM_SWITCH);
            }
            break;

        case 1:
            controllable_platform_act_1();
            break;

        case 2:
            controllable_platform_act_2();
            break;
    }

    o->oVelX = o->parentObj->oVelX;
    o->oVelZ = o->parentObj->oVelZ;

    if (o->parentObj->activeFlags == ACTIVE_FLAG_DEACTIVATED) {
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }
}

extern const BehaviorScript bhvFlame2[];
void bhv_controllable_platform_init(void) {
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvFlame, &d);
    if (!o->parentObj)
        o->parentObj = spawn_object(o, MODEL_BLUE_FLAME, bhvFlame);

    o->oControllablePlatformFlameTop = cur_obj_find_nearest_object_with_behavior(bhvFlame2, &d);
    if (!o->oControllablePlatformFlameTop)
        o->oControllablePlatformFlameTop = spawn_object(o, MODEL_BLUE_FLAME, bhvFlame2);

    struct Object *sp34;

    sp34 = spawn_object_rel_with_rot(o, MODEL_HMC_METAL_ARROW_PLATFORM, bhvControllablePlatformSub, 
                                     0, 51, 204, 0, 0, 0);
    sp34->oBehParams2ndByte = 1;
    sp34 = spawn_object_rel_with_rot(o, MODEL_HMC_METAL_ARROW_PLATFORM, bhvControllablePlatformSub, 
                                     0, 51, -204, 0, -0x8000, 0);
    sp34->oBehParams2ndByte = 2;
    sp34 = spawn_object_rel_with_rot(o, MODEL_HMC_METAL_ARROW_PLATFORM, bhvControllablePlatformSub, 
                                     204, 51, 0, 0, 0x4000, 0);
    sp34->oBehParams2ndByte = 3;
    sp34 = spawn_object_rel_with_rot(o, MODEL_HMC_METAL_ARROW_PLATFORM, bhvControllablePlatformSub,
                                     -204, 51, 0, 0, -0x4000, 0);
    sp34->oBehParams2ndByte = 4;

    sp34 = spawn_object_rel_with_rot(o, MODEL_HMC_METAL_ARROW_PLATFORM, bhvControllablePlatformSub, 
                                     204, 51, 204, 0, 0x2000, 0);
    sp34->oBehParams2ndByte = 5;
    sp34 = spawn_object_rel_with_rot(o, MODEL_HMC_METAL_ARROW_PLATFORM, bhvControllablePlatformSub, 
                                     -204, 51, -204, 0, -0x6000, 0);
    sp34->oBehParams2ndByte = 6;
    sp34 = spawn_object_rel_with_rot(o, MODEL_HMC_METAL_ARROW_PLATFORM, bhvControllablePlatformSub, 
                                     204, 51, -204, 0, 0x6000, 0);
    sp34->oBehParams2ndByte = 7;
    sp34 = spawn_object_rel_with_rot(o, MODEL_HMC_METAL_ARROW_PLATFORM, bhvControllablePlatformSub,
                                     -204, 51, 204, 0, -0x2000, 0);
    sp34->oBehParams2ndByte = 8;

    sControllablePlatformDirectionState = 0;

    o->oControllablePlatformInitPosY = o->oPosY;
}

void controllable_platform_hit_wall(s8 nextDirection) {
    o->oControllablePlatformWallHitDirection = nextDirection;
    o->oTimer = 0;
    sControllablePlatformDirectionState = 9;

    cur_obj_play_sound_2(SOUND_GENERAL_QUIET_POUND1);
#if ENABLE_RUMBLE
    queue_rumble_data(50, 80);
#endif
}

void controllable_platform_check_walls(s8 nextDirection, s8 wallDisplacement[3], Vec3f dist1, UNUSED Vec3f dist2, Vec3f dist3) {
    if (wallDisplacement[1] == 1 || (wallDisplacement[0] == 1 && wallDisplacement[2] == 1)) {
        controllable_platform_hit_wall(nextDirection);
    } else {
        if (wallDisplacement[0] == 1) {
            if (((nextDirection == 1 || nextDirection == 2) && (s32) dist1[2] != 0)
             || ((nextDirection == 3 || nextDirection == 4) && (s32) dist1[0] != 0)) {
                controllable_platform_hit_wall(nextDirection);
            } else {
                o->oPosX += dist1[0];
                o->oPosZ += dist1[2];
            }
        }

        if (wallDisplacement[2] == 1) {
            if (((nextDirection == 1 || nextDirection == 2) && (s32) dist3[2] != 0)
             || ((nextDirection == 3 || nextDirection == 4) && (s32) dist3[0] != 0)) {
                controllable_platform_hit_wall(nextDirection);
            } else {
                o->oPosX += dist3[0];
                o->oPosZ += dist3[2];
            }
        }
    }

    if (!is_point_within_radius_of_mario(o->oPosX, o->oPosY, o->oPosZ, 1000)) {
        sControllablePlatformDirectionState = 10;
        o->oControllablePlatformIsFarFromMario = 1;
        o->oTimer = 0;
    }
}

void controllable_platform_shake_on_wall_hit(void) {
    if (o->oControllablePlatformWallHitDirection == 1 || o->oControllablePlatformWallHitDirection == 2) {
        o->oFaceAnglePitch = sins(o->oTimer * 0x1000) * DEGREES(1.0f) * 10.0f;
        o->oPosY = o->oControllablePlatformInitPosY + sins(o->oTimer * 0x2000) * 20.0f;
    } else {
        o->oFaceAngleRoll = sins(o->oTimer * 0x1000) * DEGREES(1.0f) * 10.0f;
        o->oPosY = o->oControllablePlatformInitPosY + sins(o->oTimer * 0x2000) * 20.0f;
    }

    if (o->oTimer == 16) {
        sControllablePlatformDirectionState = o->oControllablePlatformWallHitDirection;
        o->oFaceAnglePitch = 0;
        o->oFaceAngleRoll = 0;
        o->oPosY = o->oControllablePlatformInitPosY;
    }
}

void controllable_platform_tilt_from_mario(void) {
    s16 dx = gMarioObject->header.gfx.pos[0] - o->oPosX;
    s16 dz = gMarioObject->header.gfx.pos[2] - o->oPosZ;

    if (gMarioObject->platform == o
        || gMarioObject->platform == cur_obj_nearest_object_with_behavior(bhvControllablePlatformSub)) {
        o->oFaceAnglePitch = dz * 4;
        o->oFaceAngleRoll = -dx * 4;
        if (sControllablePlatformDirectionState == 10) {
            sControllablePlatformDirectionState = 0;
            o->oTimer = 0;
            o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
        }
    }
}

void bhv_controllable_platform_loop(void) {
    s8 wallDisplacement[3];
    Vec3f dist1, dist2, dist3;

    o->oAngleVelRoll = 0;
    o->oAngleVelPitch = 0;
    o->oVelX = 0;
    o->oVelZ = 0;

    switch (sControllablePlatformDirectionState) {
        case 0:
            o->oFaceAnglePitch /= 2;
            o->oFaceAngleRoll /= 2;
            if (o->oControllablePlatformIsFarFromMario == 1 && o->oTimer > 30) {
                sControllablePlatformDirectionState = 10;
                o->oTimer = 0;
            }
            break;

        case 1:
            o->oVelZ = 8.0f;
            wallDisplacement[0] = obj_find_wall_displacement(dist1, o->oPosX + 250.0, o->oPosY, o->oPosZ + 300.0, 50.0f);
            wallDisplacement[1] = obj_find_wall_displacement(dist2, o->oPosX,         o->oPosY, o->oPosZ + 300.0, 50.0f);
            wallDisplacement[2] = obj_find_wall_displacement(dist3, o->oPosX - 250.0, o->oPosY, o->oPosZ + 300.0, 50.0f);
            controllable_platform_check_walls(2, wallDisplacement, dist1, dist2, dist3);
            break;

        case 2:
            o->oVelZ = -8.0f;
            wallDisplacement[0] = obj_find_wall_displacement(dist1, o->oPosX + 250.0, o->oPosY, o->oPosZ - 300.0, 50.0f);
            wallDisplacement[1] = obj_find_wall_displacement(dist2, o->oPosX,         o->oPosY, o->oPosZ - 300.0, 50.0f);
            wallDisplacement[2] = obj_find_wall_displacement(dist3, o->oPosX - 250.0, o->oPosY, o->oPosZ - 300.0, 50.0f);
            controllable_platform_check_walls(1, wallDisplacement, dist1, dist2, dist3);
            break;

        case 3:
            o->oVelX = 8.0f;
            wallDisplacement[0] = obj_find_wall_displacement(dist1, o->oPosX + 300.0, o->oPosY, o->oPosZ + 250.0, 50.0f);
            wallDisplacement[1] = obj_find_wall_displacement(dist2, o->oPosX + 300.0, o->oPosY, o->oPosZ        , 50.0f);
            wallDisplacement[2] = obj_find_wall_displacement(dist3, o->oPosX + 300.0, o->oPosY, o->oPosZ - 250.0, 50.0f);
            controllable_platform_check_walls(4, wallDisplacement, dist1, dist2, dist3);
            break;

        case 4:
            o->oVelX = -8.0f;
            wallDisplacement[0] = obj_find_wall_displacement(dist1, o->oPosX - 300.0, o->oPosY, o->oPosZ + 250.0, 50.0f);
            wallDisplacement[1] = obj_find_wall_displacement(dist2, o->oPosX - 300.0, o->oPosY, o->oPosZ        , 50.0f);
            wallDisplacement[2] = obj_find_wall_displacement(dist3, o->oPosX - 300.0, o->oPosY, o->oPosZ - 250.0, 50.0f);
            controllable_platform_check_walls(3, wallDisplacement, dist1, dist2, dist3);
            break;

        case 5:
            o->oVelX = 8.0f;
            o->oVelZ = 8.0f;
            wallDisplacement[0] = obj_find_wall_displacement(dist1, o->oPosX + 250.0, o->oPosY, o->oPosZ + 250.0, 50.0f);
            wallDisplacement[1] = obj_find_wall_displacement(dist2, o->oPosX,         o->oPosY, o->oPosZ        , 50.0f);
            wallDisplacement[2] = obj_find_wall_displacement(dist3, o->oPosX - 250.0, o->oPosY, o->oPosZ - 250.0, 50.0f);
            controllable_platform_check_walls(2, wallDisplacement, dist1, dist2, dist3);
            break;

        case 6:
            o->oVelX = -8.0f;
            o->oVelZ = -8.0f;
            wallDisplacement[0] = obj_find_wall_displacement(dist1, o->oPosX + 250.0, o->oPosY, o->oPosZ + 250.0, 50.0f);
            wallDisplacement[1] = obj_find_wall_displacement(dist2, o->oPosX,         o->oPosY, o->oPosZ        , 50.0f);
            wallDisplacement[2] = obj_find_wall_displacement(dist3, o->oPosX - 250.0, o->oPosY, o->oPosZ - 250.0, 50.0f);
            controllable_platform_check_walls(1, wallDisplacement, dist1, dist2, dist3);
            break;

        case 7:
            o->oVelX = 8.0f;
            o->oVelZ = -8.0f;
            wallDisplacement[0] = obj_find_wall_displacement(dist1, o->oPosX + 250.0, o->oPosY, o->oPosZ + 250.0, 50.0f);
            wallDisplacement[1] = obj_find_wall_displacement(dist2, o->oPosX,         o->oPosY, o->oPosZ        , 50.0f);
            wallDisplacement[2] = obj_find_wall_displacement(dist3, o->oPosX - 250.0, o->oPosY, o->oPosZ - 250.0, 50.0f);
            controllable_platform_check_walls(4, wallDisplacement, dist1, dist2, dist3);
            break;

        case 8:
            o->oVelX = -8.0f;
            o->oVelZ = 8.0f;
            wallDisplacement[0] = obj_find_wall_displacement(dist1, o->oPosX + 250.0, o->oPosY, o->oPosZ + 250.0, 50.0f);
            wallDisplacement[1] = obj_find_wall_displacement(dist2, o->oPosX,         o->oPosY, o->oPosZ        , 50.0f);
            wallDisplacement[2] = obj_find_wall_displacement(dist3, o->oPosX - 250.0, o->oPosY, o->oPosZ - 250.0, 50.0f);
            controllable_platform_check_walls(3, wallDisplacement, dist1, dist2, dist3);
            break;

        case 9:
            controllable_platform_shake_on_wall_hit();
            goto flame_ctl;

        case 10:
            if (obj_flicker_and_disappear(o, 150) || (gMarioStates->pos[2] > 9000.f)) {
                o->activeFlags = 0;
                spawn_object_abs_with_rot(o, 0, MODEL_HMC_METAL_PLATFORM, bhvControllablePlatform,
                                          o->oHomeX, o->oHomeY, o->oHomeZ, 0, 0, 0);
            }
            break;
    }

    controllable_platform_tilt_from_mario();
    o->oPosX += o->oVelX;
    o->oPosZ += o->oVelZ;
    if (sControllablePlatformDirectionState != 0 && sControllablePlatformDirectionState != 10) {
        cur_obj_play_sound_1(SOUND_ENV_ELEVATOR2);
    }

flame_ctl:
    load_object_collision_model();

    f32 d = ((6000.f - gMarioStates->pos[2]) / 10.f);
    static s16 flameTimer = 0;
    flameTimer += (369 + d);
    const f32 upd = 100.f;
    o->parentObj->oPosX = o->oPosX + 244.f * sins(flameTimer);
    o->parentObj->oPosZ = o->oPosZ + 244.f * coss(flameTimer);
    o->parentObj->oPosY = find_floor_height(o->parentObj->oPosX, o->oPosY + 200.0f, o->parentObj->oPosZ) + upd;
    if (o->parentObj->oPosY < o->oPosY)
    {
        o->parentObj->oPosY = 51.f + upd + o->oPosY;
    }

    f32 zup = (-7000.f - o->oPosX) / 2.f;
    if (zup < 0)
        zup = 0.f;

    o->oControllablePlatformFlameTop->oPosX = o->oPosX;
    o->oControllablePlatformFlameTop->oPosZ = o->oPosZ;
    o->oControllablePlatformFlameTop->oPosY = o->oPosY + 151.f + zup;
}
