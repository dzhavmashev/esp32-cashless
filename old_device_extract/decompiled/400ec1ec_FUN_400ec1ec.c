// Function : FUN_400ec1ec
// Address  : 0x400ec1ec
// Size     : 43 bytes


undefined4 FUN_400ec1ec(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = *(char *)(*param_1 + param_1[2]);
  *(undefined1 *)((int)param_1 + 0x16) = 0;
  *(undefined1 *)((int)param_1 + 0x17) = 0;
  param_1[4] = (int)&LAB_400ec520;
  *(char *)((int)param_1 + 0x15) = cVar1;
  *(undefined1 *)(param_1 + 6) = 0;
  uVar2 = 1;
  if (cVar1 != '\0') {
    uVar2 = 2;
  }
  return uVar2;
}

