// Function : FUN_400f0598
// Address  : 0x400f0598
// Size     : 66 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f0598(undefined4 param_1,int param_2)

{
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_4017435c(auStack_34,&DAT_3f40a4f4,*(undefined1 *)(param_2 + 4),*(undefined1 *)(param_2 + 5),
               *(undefined1 *)(param_2 + 6),*(undefined1 *)(param_2 + 7));
  FUN_400f0be8(param_1,auStack_34);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
  }
  return;
}

