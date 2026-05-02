// Function : FUN_4010cddc
// Address  : 0x4010cddc
// Size     : 102 bytes


void FUN_4010cddc(int param_1,short param_2)

{
  uint uVar1;
  ushort uVar2;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x3c) == 1) {
      (*(code *)&SUB_40094c54)(" LISTEN",0x3d4,"slowtmr"," 0xffff");
    }
    uVar2 = *(ushort *)(param_1 + 0x54) + param_2;
    if ((uVar2 < *(ushort *)(param_1 + 0x54)) || (0x1680 < uVar2)) {
      uVar2 = 0x1680;
    }
    *(ushort *)(param_1 + 0x54) = uVar2;
    memw();
    memw();
    uVar1 = FUN_4010cd5c(param_1);
    if (0x59f < uVar1) {
      *(ushort *)(param_1 + 0x46) = *(ushort *)(param_1 + 0x46) | 2;
      memw();
      memw();
      FUN_40112a70(param_1);
    }
  }
  return;
}

