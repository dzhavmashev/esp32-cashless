// Function : FUN_401863d8
// Address  : 0x401863d8
// Size     : 24 bytes


undefined4 FUN_401863d8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(int *)(param_1 + 0x30) != 0) && (uVar1 = 1, *(int *)(param_1 + 0x3c) == 0)) {
    uVar1 = 2;
  }
  return uVar1;
}

