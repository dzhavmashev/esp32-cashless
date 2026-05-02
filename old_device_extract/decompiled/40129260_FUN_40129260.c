// Function : FUN_40129260
// Address  : 0x40129260
// Size     : 848 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40129260(undefined4 param_1,int param_2,int param_3,code *param_4,undefined4 param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int in_t0;
  int iStack_a0;
  int iStack_9c;
  undefined4 uStack_8c;
  int local_88;
  undefined1 auStack_82 [46];
  undefined1 auStack_54 [48];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if ((param_3 != 0) && (iStack_9c = 0, param_2 != 0)) goto LAB_401292b0;
LAB_4012928d:
  do {
    iVar5 = -0x6c00;
LAB_40129290:
    do {
      iStack_9c = in_t0;
      param_3 = _DAT_3ffc5708;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return iVar5;
      }
      memw();
      (*(code *)&SUB_40082ec4)();
      in_t0 = iStack_9c;
LAB_401292b0:
      if (*(int *)(param_3 + 0xc) == 0) goto LAB_4012928d;
      uVar1 = *(uint *)(param_3 + 0x10);
      uVar2 = *(uint *)(param_3 + 0x14);
      if ((uVar1 < uVar2) || (uVar6 = *(uint *)(param_3 + 0x18), uVar1 - uVar2 < uVar6))
      goto LAB_4012928d;
      iStack_a0 = *(int *)(param_3 + 0xc) + uVar2;
      uVar1 = uVar1 - (uVar2 + uVar6);
      if (*(int *)(param_2 + 0x50) == 0) {
        iVar5 = -0x7100;
        if (0x4000 < uVar6) goto LAB_40129290;
        memw();
        uVar2 = 0;
        iStack_9c = 0;
      }
      else {
        uVar2 = *(uint *)(*(int *)(param_2 + 0x50) + 4);
        iVar5 = -0x7100;
        if (0x4000 < uVar6) goto LAB_40129290;
        if (uVar2 == 7) {
LAB_401292ed:
          iVar5 = -0x6a00;
          if (uVar1 < *(uint *)(param_2 + 0xc)) goto LAB_40129290;
          if (*(int *)(param_2 + 0xd0) < 1) goto LAB_4012928d;
          memw();
          FUN_401291b0(auStack_82,&uStack_8c,param_3);
          iVar3 = param_2 + 0x34;
          iVar5 = FUN_4013935c(iVar3,auStack_82,uStack_8c);
          if ((((iVar5 == 0) &&
               (iVar5 = FUN_4013935c(iVar3,iStack_a0,*(undefined4 *)(param_3 + 0x18)), iVar5 == 0))
              && (iVar5 = FUN_4013937c(iVar3,auStack_54), iVar5 == 0)) &&
             (iVar5 = FUN_401393f0(iVar3), iVar5 == 0)) {
            (*(code *)&SUB_4008b3d0)
                      (iStack_a0 + *(int *)(param_3 + 0x18),auStack_54,
                       *(undefined4 *)(param_2 + 0xc));
          }
          FUN_4013ae54(auStack_54,*(undefined4 *)(param_2 + 0xc));
          if (iVar5 != 0) goto LAB_40129290;
          iStack_9c = 1;
          uVar1 = uVar1 - *(int *)(param_2 + 0xc);
          *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + *(int *)(param_2 + 0xc);
        }
        else if (uVar2 == 2) {
          if (*(int *)(param_2 + 0x4c) == 0) goto LAB_401292ed;
          iStack_9c = 0;
          memw();
        }
      }
      if (((uVar2 & 0xfffffffd) == 8) || (uVar2 == 6)) {
        if (uVar1 < *(uint *)(param_2 + 0x10)) {
LAB_4012959c:
          iVar5 = -0x6a00;
          goto LAB_40129290;
        }
        iVar3 = *(int *)(param_2 + 8);
        iVar4 = *(int *)(param_2 + 4);
        memw();
        FUN_40129220(auStack_54,param_2 + 0x14,iVar3,param_3);
        FUN_401291b0(auStack_82,&uStack_8c,param_3);
        memw();
        iVar5 = FUN_401330f4(param_2 + 0x50,auStack_54,*(undefined4 *)(param_2 + 4),auStack_82,
                             uStack_8c,iStack_a0,*(undefined4 *)(param_3 + 0x18),iStack_a0,
                             *(int *)(param_3 + 0x10) - (iStack_a0 - *(int *)(param_3 + 0xc)),
                             param_3 + 0x18,*(undefined4 *)(param_2 + 0x10));
        if (iVar5 != 0) goto LAB_40129290;
        if (iVar4 != iVar3) {
          if (*(uint *)(param_3 + 0x14) < 8) goto LAB_4012959c;
          (*(code *)&SUB_4008b3d0)(iStack_a0 + -8,param_3,8);
          *(int *)(param_3 + 0x14) = *(int *)(param_3 + 0x14) + -8;
          *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 8;
        }
        iStack_9c = iStack_9c + 1;
      }
      else {
        if (uVar2 != 2) goto LAB_4012928d;
        uVar6 = *(uint *)(param_2 + 4);
        uVar2 = uVar6 - (*(int *)(param_3 + 0x18) + 1U) % uVar6;
        if (uVar6 == uVar2) {
          uVar2 = 0;
        }
        if (uVar1 < uVar2 + 1) goto LAB_4012959c;
        uVar6 = 0;
        do {
          iVar5 = iStack_a0 + uVar6;
          uVar6 = uVar6 + 1;
          *(char *)(iVar5 + *(int *)(param_3 + 0x18)) = (char)uVar2;
          memw();
        } while (uVar6 <= uVar2);
        *(uint *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1 + uVar2;
        if (1 < *(int *)(param_2 + 0xd0)) {
          if (param_4 == (code *)0x0) goto LAB_4012928d;
          if (*(uint *)(param_3 + 0x14) < *(uint *)(param_2 + 4)) goto LAB_4012959c;
          memw();
          iVar5 = (*param_4)(param_5,param_2 + 0x14);
          if (iVar5 != 0) goto LAB_40129290;
          (*(code *)&SUB_4008b3d0)
                    (iStack_a0 - *(int *)(param_2 + 4),param_2 + 0x14,*(int *)(param_2 + 4));
        }
        memw();
        iVar5 = FUN_4013309c(param_2 + 0x50,param_2 + 0x14,*(undefined4 *)(param_2 + 4),iStack_a0,
                             *(undefined4 *)(param_3 + 0x18),iStack_a0,&local_88);
        if (iVar5 != 0) goto LAB_40129290;
        if (*(int *)(param_3 + 0x18) != local_88) goto LAB_4012928d;
        iVar3 = *(int *)(param_2 + 4);
        if (*(int *)(param_2 + 0xd0) < 2) {
          (*(code *)&SUB_4008b3d0)(param_2 + 0x14,param_2 + 0x78);
        }
        else {
          iStack_a0 = iStack_a0 - iVar3;
          *(int *)(param_3 + 0x14) = *(int *)(param_3 + 0x14) - iVar3;
          *(int *)(param_3 + 0x18) = iVar3 + *(int *)(param_3 + 0x18);
          memw();
        }
        if ((iStack_9c != 0) || (iVar5 = -0x6a00, (uVar1 - 1) - uVar2 < *(uint *)(param_2 + 0xc)))
        goto LAB_40129290;
        FUN_401291b0(auStack_82,&uStack_8c,param_3);
        iVar3 = param_2 + 0x34;
        iVar5 = FUN_4013935c(iVar3,auStack_82,uStack_8c);
        if (iVar5 == 0) {
          iVar5 = FUN_4013935c(iVar3,iStack_a0,*(undefined4 *)(param_3 + 0x18));
          iStack_9c = 0;
          if (iVar5 == 0) {
            iVar5 = FUN_4013937c(iVar3,auStack_54);
            if (iVar5 == 0) {
              iVar5 = FUN_401393f0(iVar3);
              iStack_9c = 0;
              if (iVar5 == 0) {
                (*(code *)&SUB_4008b3d0)
                          (iStack_a0 + *(int *)(param_3 + 0x18),auStack_54,
                           *(undefined4 *)(param_2 + 0xc));
                iStack_9c = 1;
                *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + *(int *)(param_2 + 0xc);
              }
            }
            else {
              iStack_9c = 0;
            }
          }
        }
        else {
          iStack_9c = 0;
        }
        memw();
        FUN_4013ae54(auStack_54,*(undefined4 *)(param_2 + 0xc));
        if (iVar5 != 0) goto LAB_40129290;
      }
      iVar5 = 0;
    } while (iStack_9c == 1);
    memw();
  } while( true );
}

