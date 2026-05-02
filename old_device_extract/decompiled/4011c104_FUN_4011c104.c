// Function : FUN_4011c104
// Address  : 0x4011c104
// Size     : 63 bytes


undefined1 FUN_4011c104(int param_1,int param_2,int param_3,undefined1 param_4)

{
  undefined1 uVar1;
  int aiStack_48 [2];
  int iStack_40;
  int iStack_3c;
  undefined1 uStack_38;
  
  if ((param_2 == 0 || param_3 == 0) || (param_1 == 0)) {
    uVar1 = 0xf0;
  }
  else {
    memw();
    memw();
    aiStack_48[0] = param_1;
    iStack_40 = param_2;
    iStack_3c = param_3;
    uStack_38 = param_4;
    uVar1 = FUN_4011bff4(&LAB_4011d714,aiStack_48);
  }
  return uVar1;
}

