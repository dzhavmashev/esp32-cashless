// Function : FUN_400dbfa8
// Address  : 0x400dbfa8
// Size     : 94 bytes


void FUN_400dbfa8(undefined1 *param_1)

{
  int iVar1;
  bool bVar2;
  char *pcVar3;
  
  if ((param_1[5] != '\0') &&
     (iVar1 = FUN_400f1a9c(),
     (uint)*(ushort *)(param_1 + 2) <= (uint)(iVar1 - *(int *)(param_1 + 8)))) {
    *(int *)(param_1 + 8) = iVar1;
    if (param_1[1] == '\0') {
      iVar1 = FUN_400f1a50(*param_1);
      bVar2 = iVar1 == 1;
    }
    else {
      iVar1 = FUN_400f1a50(*param_1);
      bVar2 = iVar1 == 0;
    }
    if ((bool)param_1[4] != bVar2) {
      param_1[4] = bVar2;
      pcVar3 = "e 1)\n";
      if (bVar2 == false) {
        pcVar3 = "s found";
      }
      FUN_400f06a4(0x3ffc5490,"w=%dms\n",pcVar3);
    }
  }
  return;
}

