// Function : FUN_40159500
// Address  : 0x40159500
// Size     : 384 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40159500(int *param_1,undefined4 param_2,undefined4 param_3,short param_4,short param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    return;
  }
  iVar2 = *param_1;
  if (iVar2 == 0) {
    return;
  }
  memw();
  iVar1 = FUN_401594d4();
  if (iVar1 == 0) {
    return;
  }
  if (*(int *)(iVar2 + 0x98) != 2) {
    return;
  }
  if (((param_5 == 0 || param_5 == 0x4c) || (param_5 == 0x7e)) && ((DAT_3ffc89ec & 0xfd) == 4)) {
    memw();
    iVar1 = (**(code **)(_DAT_3ffc89a4 + 0x4c))(param_2,param_3,param_4,param_5);
    if (iVar1 == 0x4d) {
      if (param_4 != 1) {
        if (param_4 != 2) {
          return;
        }
LAB_40159612:
        FUN_40157594(&DAT_3ffc87f0,3,0);
        DAT_3ffc89f7 = 0;
        memw();
        iVar2 = iVar2 + 4;
        memw();
        (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar2);
        (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar2);
        (**(code **)(_DAT_3ffc1a34 + 0xf4))(iVar2,0x4015c258,0);
        (**(code **)(_DAT_3ffc1a34 + 0xe8))(iVar2,1000,0);
        return;
      }
    }
    else {
      if (iVar1 == 0x3017) {
        return;
      }
      if (iVar1 != 0) goto LAB_40159664;
      DAT_3ffc89f7 = (undefined1)param_4;
      memw();
      if (param_4 != 1) {
        if (param_4 != 2) {
          memw();
          return;
        }
        DAT_3ffc89f7 = 2;
        goto LAB_40159612;
      }
      if (param_5 != 0x4c) {
        FUN_40153ed0(param_1,0xb0,2);
        goto LAB_401595c6;
      }
    }
    FUN_40153ed0(param_1,0xb0,iVar1 << 0x10 | 1);
    if (iVar1 == 0) {
LAB_401595c6:
      iVar1 = iVar2 + 0x68;
      (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar1);
      (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar1);
      *(undefined1 *)(iVar2 + 0x7c) = 1;
      memw();
      memw();
      (**(code **)(_DAT_3ffc1a34 + 0xf4))(iVar1,0x4015c268,1);
      FUN_40162224(2);
      iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
      if (iVar2 == 0) {
        return;
      }
      FUN_4015c280(1);
      return;
    }
  }
LAB_40159664:
  if (*(int *)(iVar2 + 0x98) != 2) {
    return;
  }
  FUN_40157594(&DAT_3ffc87f0,0,0x600);
  return;
}

