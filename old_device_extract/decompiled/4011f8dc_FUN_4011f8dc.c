// Function : FUN_4011f8dc
// Address  : 0x4011f8dc
// Size     : 100 bytes


undefined4 FUN_4011f8dc(int *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar1 = 0x102;
  if (param_1 != (int *)0x0) {
    uVar2 = (*(code *)&SUB_40085bfc)();
    (*(code *)&SUB_40085848)(0);
    uVar1 = 0x103;
    if (*param_1 == 0 && param_1[1] == 0) {
      *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) & 0xfe;
      memw();
      *param_1 = (int)uVar2;
      param_1[4] = -0xf21e1e2;
      param_1[3] = param_1[3] & 0xff000000;
      param_1[1] = (int)((ulonglong)uVar2 >> 0x20);
      param_1[2] = 0;
      memw();
      uVar1 = (*(code *)&SUB_40085860)(param_1);
    }
    (*(code *)&SUB_400858d8)(0);
  }
  return uVar1;
}

