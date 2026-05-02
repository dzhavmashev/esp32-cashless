// Function : FUN_400e9078
// Address  : 0x400e9078
// Size     : 94 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e9078(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  if ((_DAT_3ffc51c0 == 0) && (_DAT_3ffc51c0 = func_0x4008f3cc(), _DAT_3ffc51c0 == 0)) {
    uVar3 = func_0x40085c04();
    uVar1 = FUN_401847ec("face_ip");
    uVar2 = (*(code *)&SUB_4000cff8)((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),1000,0);
    FUN_4012105c("STA.cpp",uVar2,uVar1,0x82,"n");
    _DAT_3ffbdb8c = param_1;
    return;
  }
  func_0x4008f50c(_DAT_3ffc51c0,0xffffff);
  func_0x4008f558(_DAT_3ffc51c0,param_1);
  return;
}

