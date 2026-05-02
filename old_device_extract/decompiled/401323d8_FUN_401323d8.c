// Function : FUN_401323d8
// Address  : 0x401323d8
// Size     : 394 bytes


void FUN_401323d8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  int iStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  iStack_34 = 0;
  iStack_30 = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_5c = 1;
  uStack_50 = 1;
  uStack_44 = 1;
  local_38 = 1;
  uStack_2c = 1;
  memw();
  iVar1 = FUN_40131d74(&uStack_5c,param_1);
  if (iVar1 == 0) {
    uVar2 = FUN_40186044(&uStack_5c);
    iVar1 = FUN_4013167c(&uStack_50,&uStack_5c);
    if ((iVar1 == 0) && (iVar1 = FUN_40131a34(&uStack_50,uVar2), iVar1 == 0)) {
      for (iVar1 = 0; iVar1 != param_2; iVar1 = iVar1 + 1) {
        iVar6 = 0x20;
        do {
          iVar3 = FUN_401323a8(&local_38,*(int *)(param_1 + 4) << 2,param_3,param_4);
          if (iVar3 != 0) goto LAB_401324a0;
          uVar4 = FUN_40131798(&local_38);
          memw();
          uVar5 = FUN_40131798(&uStack_5c);
          if (uVar5 < uVar4) {
            puVar7 = (uint *)(iStack_30 + iStack_34 * 4 + -4);
            *puVar7 = *puVar7 & (-1 << 0x20 - (0x20 - (uVar5 - 1 & 0x1f)) ^ 0xffffffffU);
          }
          iVar6 = iVar6 + -1;
          if (iVar6 == 0) goto LAB_401324a0;
          iVar3 = FUN_401860ec(&local_38,&uStack_5c);
        } while ((-1 < iVar3) || (iVar3 = FUN_40131ad8(&local_38,1), iVar3 < 1));
        iVar6 = FUN_4013d3d8(&local_38,&local_38,&uStack_50,param_1,&uStack_2c);
        if (iVar6 != 0) break;
        iVar6 = FUN_401860ec(&local_38,&uStack_5c);
        if (iVar6 != 0) {
          iVar6 = FUN_40131ad8(&local_38,1);
          uVar4 = 1;
          if (iVar6 != 0) {
            for (; iVar6 = FUN_401860ec(&local_38,&uStack_5c), uVar4 < uVar2; uVar4 = uVar4 + 1) {
              if (iVar6 == 0) goto LAB_4013251e;
              iVar6 = FUN_4013d5d8(&uStack_44,&local_38,&local_38);
              if ((iVar6 != 0) || (iVar6 = FUN_401320e0(&local_38,&uStack_44,param_1), iVar6 != 0))
              goto LAB_401324a0;
              iVar6 = FUN_40131ad8(&local_38,1);
              if (iVar6 == 0) break;
            }
            iVar6 = FUN_401860ec(&local_38,&uStack_5c);
            if (iVar6 != 0) break;
LAB_4013251e:
            iVar6 = FUN_40131ad8(&local_38,1);
            if (iVar6 == 0) break;
          }
        }
      }
    }
  }
LAB_401324a0:
  memw();
  FUN_40131548(&uStack_5c);
  FUN_40131548(&uStack_50);
  FUN_40131548(&uStack_44);
  FUN_40131548(&local_38);
  FUN_40131548(&uStack_2c);
  return;
}

