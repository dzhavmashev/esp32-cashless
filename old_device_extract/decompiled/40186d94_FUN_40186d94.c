// Function : FUN_40186d94
// Address  : 0x40186d94
// Size     : 200 bytes


bool FUN_40186d94(char param_1,int *param_2,int *param_3)

{
  uint uVar1;
  
  *(undefined1 *)param_2 = 0xb7;
  *(undefined1 *)((int)param_2 + 1) = 0x12;
  *(undefined1 *)((int)param_2 + 2) = 0;
  *(undefined1 *)((int)param_2 + 3) = 0;
  memw();
  uVar1 = *param_2 + *param_3 ^ 0xffffffff;
  if (param_1 != '\0') {
    return uVar1 != param_2[0x15a];
  }
  *(char *)(param_2 + 0x15a) = (char)uVar1;
  *(char *)((int)param_2 + 0x569) = (char)(uVar1 >> 8);
  *(char *)((int)param_2 + 0x56a) = (char)(uVar1 >> 0x10);
  *(char *)((int)param_2 + 0x56b) = (char)(uVar1 >> 0x18);
  memw();
  return false;
}

