// Function : FUN_400e9c18
// Address  : 0x400e9c18
// Size     : 106 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e9c18(undefined4 param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 ***pppuVar2;
  undefined4 **local_34 [3];
  byte bStack_25;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0598(local_34,param_2);
  pppuVar2 = local_34;
  if ((bStack_25 & 0x80) == 0) {
    pppuVar2 = (undefined4 ***)local_34[0];
  }
  uVar1 = FUN_400e9b4c(param_1,pppuVar2,param_3,param_4,param_5);
  FUN_400f0a50(local_34);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(local_34);
    thunk_FUN_401710d8(uVar1);
  }
  return;
}

