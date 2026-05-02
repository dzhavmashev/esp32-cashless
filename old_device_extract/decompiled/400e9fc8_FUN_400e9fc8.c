// Function : FUN_400e9fc8
// Address  : 0x400e9fc8
// Size     : 118 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e9fc8(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined1 auStack_88 [100];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (param_1 != -0x7880) {
    FUN_40138b60(param_1,auStack_88,100);
    uVar3 = func_0x40085c04();
    uVar1 = FUN_401847ec("_attach");
    uVar2 = (*(code *)&SUB_4000cff8)((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),1000,0);
    FUN_4012105c("ent.cpp",uVar2,uVar1,0x25,"to_read",param_2,param_3,param_1,auStack_88);
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
  }
  return;
}

