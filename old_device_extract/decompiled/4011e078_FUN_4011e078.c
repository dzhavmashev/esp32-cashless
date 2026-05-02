// Function : FUN_4011e078
// Address  : 0x4011e078
// Size     : 198 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4011e078(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) ||
     (iVar1 = _DAT_3ffc87d8, param_3 <= param_2)) {
    uVar3 = 0x102;
  }
  else {
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x20)) {
      if (((*(int *)(iVar1 + 0xc) < param_3) && (param_2 <= *(int *)(iVar1 + 0xc))) ||
         ((*(int *)(iVar1 + 0x10) < param_3 && (param_2 < *(int *)(iVar1 + 0x10))))) {
        return 0xffffffff;
      }
    }
    iVar1 = (*(code *)&SUB_40083fe0)(0x24,0x804);
    if (iVar1 == 0) {
      uVar3 = 0x101;
    }
    else {
      (*(code *)&SUB_4008b3d0)(iVar1,param_1,0xc);
      *(int *)(iVar1 + 0xc) = param_2;
      *(int *)(iVar1 + 0x10) = param_3;
      *(undefined4 *)(iVar1 + 0x14) = 0xb33fffff;
      *(undefined4 *)(iVar1 + 0x18) = 0;
      memw();
      iVar2 = FUN_4018e394(param_2,param_3 - param_2);
      *(int *)(iVar1 + 0x1c) = iVar2;
      *(undefined4 *)(iVar1 + 0x20) = 0;
      if (iVar2 != 0) {
        memw();
        (*(code *)&SUB_40094924)(iVar2,iVar1 + 0x14);
        (*(code *)&SUB_40092a98)(0x3ffbe0f0,0xffffffff);
        *(int *)(iVar1 + 0x20) = _DAT_3ffc87d8;
        memw();
        _DAT_3ffc87d8 = iVar1;
        (*(code *)&SUB_40092bec)(0x3ffbe0f0);
        return 0;
      }
      uVar3 = 0x104;
    }
    (*(code *)&SUB_40094d80)(iVar1);
  }
  return uVar3;
}

