// Function : FUN_4013d3d8
// Address  : 0x4013d3d8
// Size     : 510 bytes


int FUN_4013d3d8(undefined4 *param_1,int *param_2,int param_3,int param_4,undefined1 *param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 auStack_44 [12];
  undefined1 auStack_38 [12];
  undefined1 auStack_2c [44];
  
  memw();
  uVar1 = FUN_401866cc(param_2);
  uVar2 = FUN_401866cc(param_3);
  uVar3 = FUN_401866cc(param_4);
  uVar1 = (uVar1 < uVar2) * uVar2 + (uVar1 >= uVar2) * uVar1;
  iVar4 = FUN_40186728((uVar1 < uVar3) * uVar3 + (uVar1 >= uVar3) * uVar1);
  iVar9 = -0xe;
  if ((uint)(iVar4 << 5) < 0x1001) {
    iVar9 = FUN_40131ad8(param_4,0);
    if (((iVar9 < 1) || ((**(uint **)(param_4 + 8) & 1) == 0)) ||
       (iVar9 = FUN_40131ad8(param_3,0), iVar9 < 0)) {
      iVar9 = -4;
    }
    else {
      iVar9 = FUN_40131ad8(param_3,0);
      if (iVar9 == 0) {
        iVar9 = FUN_40131700(param_1,1);
      }
      else {
        puVar6 = param_5;
        if (param_5 == (undefined1 *)0x0) {
          FUN_40186008(auStack_44);
          puVar6 = auStack_44;
        }
        if ((*(int *)(puVar6 + 8) != 0) || (iVar9 = FUN_4013d32c(puVar6,param_4,iVar4), iVar9 == 0))
        {
          uVar5 = FUN_4013d35c(*(undefined4 *)(param_4 + 8));
          memw();
          FUN_40186008(auStack_38);
          FUN_40186008(auStack_2c);
          iVar9 = FUN_40131574(auStack_2c,iVar4);
          if ((iVar9 == 0) && (iVar9 = FUN_4013173c(auStack_2c,0,1), iVar9 == 0)) {
            iVar8 = 0;
            iVar9 = 0;
            if (param_3 != 0) {
              iVar7 = *(int *)(param_3 + 4);
              iVar8 = 0;
              if (iVar7 != 0) {
                do {
                  iVar7 = iVar7 + -1;
                  if (iVar7 < 0) {
                    iVar8 = 0;
                    goto LAB_4013d494;
                  }
                  iVar9 = iVar7 * 4;
                  uVar1 = *(uint *)(*(int *)(param_3 + 8) + iVar9);
                } while ((uVar1 == 0) || (iVar9 = 0x20, (uVar1 & 0x80000000) == 0));
                iVar8 = iVar7 * 0x20 + 0x1f;
              }
            }
LAB_4013d494:
            FUN_4013d7fc(iVar9);
            memw();
            iVar9 = FUN_4013d8c8(auStack_38,param_2,puVar6,param_4,uVar5,iVar4,0);
            if (iVar9 == 0) {
              memw();
              iVar9 = FUN_4013d8c8(param_1,puVar6,auStack_2c,param_4,uVar5,iVar4,1);
              iVar7 = iVar8;
              if (iVar9 == 0) {
                for (; -1 < iVar7; iVar7 = iVar7 + -1) {
                  if (iVar8 != iVar7) {
                    memw();
                    iVar9 = FUN_4013d8c8(param_1,param_1,param_1,param_4,uVar5,iVar4,1);
                    if (iVar9 != 0) goto LAB_4013d58d;
                  }
                  iVar9 = FUN_4018601c(param_3,iVar7);
                  if (iVar9 != 0) {
                    memw();
                    iVar9 = FUN_4013d8c8(param_1,param_1,auStack_38,param_4,uVar5,iVar4,1);
                    if (iVar9 != 0) goto LAB_4013d58d;
                  }
                }
                memw();
                iVar9 = FUN_4013d8c8(param_1,param_1,auStack_2c,param_4,uVar5,iVar4,1);
              }
            }
LAB_4013d58d:
            memw();
            FUN_4013d838();
          }
          memw();
          FUN_40131548(auStack_38);
          FUN_40131548(auStack_2c);
          if (iVar9 == 0) {
            if ((*param_2 == -1) && ((**(uint **)(param_3 + 8) & 1) != 0)) {
              *param_1 = 0xffffffff;
              memw();
              iVar9 = FUN_40131d18(param_1,param_4,param_1);
            }
            else {
              *param_1 = 1;
              memw();
            }
          }
        }
        if (param_5 == (undefined1 *)0x0) {
          memw();
          FUN_40131548(auStack_44);
        }
      }
    }
  }
  return iVar9;
}

