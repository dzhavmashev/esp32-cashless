// Function : FUN_40185360
// Address  : 0x40185360
// Size     : 8 bytes


void FUN_40185360(int *param_1,ushort param_2,ushort *param_3)

{
  while( true ) {
    param_1 = (int *)*param_1;
    if ((param_1 == (int *)0x0) || (param_2 < *(ushort *)((int)param_1 + 10))) break;
    param_2 = param_2 - *(ushort *)((int)param_1 + 10);
  }
  if (param_3 != (ushort *)0x0) {
    *param_3 = param_2;
    memw();
  }
  memw();
  return;
}

