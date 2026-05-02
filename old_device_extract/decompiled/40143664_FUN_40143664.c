// Function : FUN_40143664
// Address  : 0x40143664
// Size     : 74 bytes


void FUN_40143664(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_40143560(param_1);
  (*(code *)&SUB_40092a98)(0x3ffbf7b4,0xffffffff);
  DAT_3ffc78d0 = DAT_3ffc78d0 + -1;
  memw();
  if (DAT_3ffc78d0 == '\0') {
    memw();
    FUN_400f55ec(0x1f);
  }
  (*(code *)&SUB_40092bec)(0x3ffbf7b4);
  (*(code *)&SUB_4008fab8)(uVar1,0,0);
  return;
}

