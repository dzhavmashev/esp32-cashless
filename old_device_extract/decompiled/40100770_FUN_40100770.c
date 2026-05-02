// Function : FUN_40100770
// Address  : 0x40100770
// Size     : 30 bytes


void FUN_40100770(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 != 0) && (*(code **)(param_1 + 8) != (code *)0x0)) {
    uVar1 = (**(code **)(param_1 + 8))(param_1);
    *(undefined4 *)(param_1 + 4) = uVar1;
    memw();
    FUN_4011ad9c(&DAT_3ffc5860);
  }
  return;
}

