// Function : FUN_400e2fd8
// Address  : 0x400e2fd8
// Size     : 151 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_400e2fd8(undefined4 *param_1)

{
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0be8(auStack_34,"version");
  *param_1 = 0;
  FUN_400f0d4c(param_1 + 1,auStack_34);
  param_1[5] = 0;
  FUN_400f0a50(auStack_34);
  FUN_400f0be8(auStack_34,"seconds");
  FUN_400e2f28(param_1,auStack_34,5);
  FUN_400f0a50(auStack_34);
  if (DAT_3ffc4ac1 == '\0') {
    DAT_3ffc4ac1 = '\x01';
    func_0x40090934(0x400e46cc,"seconds",0x800,0,1,0,0x7fffffff);
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
  }
  return param_1;
}

