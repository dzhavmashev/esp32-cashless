// Function : FUN_40116274
// Address  : 0x40116274
// Size     : 43 bytes


void FUN_40116274(int param_1,uint param_2)

{
  if ((*(char *)(param_1 + 9) == '\x02') ||
     ((*(char *)(param_1 + 9) == '\x01' &&
      ((*(ushort *)(param_1 + 10) == 0 || (param_2 < *(ushort *)(param_1 + 10))))))) {
    FUN_40116228(param_1,param_2);
    *(undefined1 *)(param_1 + 9) = 1;
    memw();
  }
  memw();
  return;
}

