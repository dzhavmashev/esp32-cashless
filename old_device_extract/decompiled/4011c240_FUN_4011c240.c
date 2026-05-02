// Function : FUN_4011c240
// Address  : 0x4011c240
// Size     : 32 bytes


undefined1 FUN_4011c240(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int aiStack_48 [2];
  undefined4 uStack_40;
  
  uVar1 = 0xf0;
  if (param_1 != 0) {
    memw();
    aiStack_48[0] = param_1;
    uStack_40 = param_2;
    uVar1 = FUN_4011bff4(&LAB_4011d544,aiStack_48);
  }
  return uVar1;
}

