// Function : FUN_4011c014
// Address  : 0x4011c014
// Size     : 44 bytes


undefined1 FUN_4011c014(int param_1,undefined1 param_2)

{
  undefined1 uVar1;
  int aiStack_48 [2];
  undefined1 uStack_40;
  undefined4 uStack_3c;
  
  uVar1 = 0xf0;
  if (param_1 != 0) {
    memw();
    memw();
    aiStack_48[0] = param_1;
    uStack_40 = param_2;
    uStack_3c = FUN_4011b010();
    memw();
    uVar1 = FUN_4011bff4(&DAT_4011d828,aiStack_48);
  }
  return uVar1;
}

