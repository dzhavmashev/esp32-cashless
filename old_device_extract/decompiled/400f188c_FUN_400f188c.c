// Function : FUN_400f188c
// Address  : 0x400f188c
// Size     : 153 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f188c(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_40 [12];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar1 = func_0x40094d68(((uint)(param_3 << 2) / 3 + 3 & 0xfffffffc) + 1);
  if (iVar1 == 0) goto LAB_400f1915;
  FUN_40184834(auStack_40);
  iVar2 = FUN_400f2f64(param_2,param_3,iVar1,auStack_40);
  FUN_400f3038(iVar1 + iVar2,auStack_40);
  FUN_400f0be8(auStack_34,iVar1);
  func_0x40094d88(iVar1);
  FUN_400f0d04(param_1,auStack_34);
  FUN_400f0a50(auStack_34);
  while( true ) {
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
LAB_400f1915:
    FUN_400f0be8(param_1,"");
  }
  return;
}

