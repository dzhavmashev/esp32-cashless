// Function : FUN_4011c0b8
// Address  : 0x4011c0b8
// Size     : 36 bytes


undefined1 FUN_4011c0b8(int param_1)

{
  undefined1 uVar1;
  int aiStack_48 [3];
  undefined4 uStack_3c;
  
  uVar1 = 0;
  if (param_1 != 0) {
    memw();
    aiStack_48[0] = param_1;
    uStack_3c = FUN_4011b010();
    memw();
    uVar1 = FUN_4011bff4(0x4011d2a8,aiStack_48);
  }
  return uVar1;
}

