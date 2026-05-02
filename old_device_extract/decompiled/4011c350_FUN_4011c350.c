// Function : FUN_4011c350
// Address  : 0x4011c350
// Size     : 34 bytes


undefined1 FUN_4011c350(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    FUN_4011b020();
    uVar1 = *(undefined1 *)(param_1 + 0xc);
    *(undefined1 *)(param_1 + 0xc) = 0;
    memw();
    memw();
    FUN_4011b040();
  }
  return uVar1;
}

