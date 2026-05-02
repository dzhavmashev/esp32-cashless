// Function : FUN_4011c1fc
// Address  : 0x4011c1fc
// Size     : 28 bytes


undefined1 FUN_4011c1fc(int param_1)

{
  undefined1 uVar1;
  int aiStack_48 [18];
  
  uVar1 = 0xf0;
  if (param_1 != 0) {
    memw();
    aiStack_48[0] = param_1;
    uVar1 = FUN_4011bff4(&LAB_4011d514,aiStack_48);
  }
  return uVar1;
}

