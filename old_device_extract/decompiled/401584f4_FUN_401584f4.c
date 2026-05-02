// Function : FUN_401584f4
// Address  : 0x401584f4
// Size     : 317 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401584f4(int *param_1,undefined4 param_2,char *param_3,char *param_4,undefined4 param_5,
                 undefined4 param_6,ushort param_7,short param_8)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  
  uVar3 = (uint)param_7;
  if (param_1 == (int *)0x0) {
    return;
  }
  iVar2 = *param_1;
  if (iVar2 == 0) {
    return;
  }
  if (param_8 == 0xd) {
    DAT_3ffc89ec = '\x02';
    memw();
    memw();
    FUN_40147fe4(1,4,4,0x3f433d55,0xd);
    uVar5 = 1;
    goto LAB_401585f7;
  }
  if (((*(uint *)(iVar2 + 0xa4) & 0x10) != 0) && ((DAT_3ffc89ec - 2U & 0xfd) == 0)) {
    if (param_3 + 1 < param_4) {
      if ((int)((byte)param_3[1] + 1) < (int)param_4 - (int)param_3) {
        if (*param_3 != '\x10') goto LAB_40158628;
        if ((uVar3 - 2 < 2) && ((byte)param_3[1] != 0x80)) goto LAB_40158604;
        goto LAB_40158598;
      }
    }
    else {
      if ((param_3 == param_4 && uVar3 == 2) && (param_8 == 0)) {
        return;
      }
LAB_40158628:
      param_3 = (char *)0x0;
      if (1 < uVar3 - 2) {
LAB_40158598:
        if (*(int *)(iVar2 + 0x98) != 2) {
          return;
        }
        if (uVar3 == 2) {
          iVar1 = FUN_4014c7dc(iVar2);
          if (iVar1 == 0) {
            return;
          }
          (*(code *)&SUB_4008b3d0)(*(undefined4 *)(iVar2 + 0xb0),param_3 + 2,param_3[1]);
          FUN_40147fe4(1,4,4,0x3f433d32,3);
          uVar5 = 3;
LAB_401585f7:
          FUN_40153ed0(param_1,0xb0,uVar5);
          return;
        }
        if (uVar3 != 4) {
          return;
        }
        if (*(int *)(iVar2 + 0xb0) != 0) {
          (**(code **)(_DAT_3ffc1a34 + 0xb0))();
          *(undefined4 *)(iVar2 + 0xb0) = 0;
        }
        if (param_8 != 0) {
          return;
        }
        uVar5 = 3;
        memw();
        uVar4 = 0;
        goto LAB_40158612;
      }
    }
  }
LAB_40158604:
  if (*(int *)(iVar2 + 0x98) != 2) {
    return;
  }
  uVar4 = 0x600;
  uVar5 = 0;
LAB_40158612:
  FUN_40157594(&DAT_3ffc87f0,uVar5,uVar4);
  return;
}

