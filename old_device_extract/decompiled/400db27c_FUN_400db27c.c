// Function : FUN_400db27c
// Address  : 0x400db27c
// Size     : 152 bytes


void FUN_400db27c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  FUN_400eb9cc(param_1);
  if (*(int *)(param_1 + 0x800) == 2) {
    FUN_400daa1c(param_1);
  }
  else if (((*(char *)(param_1 + 0x80c) != '\0') && (*(int *)(param_1 + 0x800) != 1)) &&
          (iVar1 = FUN_400f1a9c(), 30000 < (uint)(iVar1 - *(int *)(param_1 + 0x804)))) {
    FUN_400f0780(0x3ffc5490,"s: %d)\n");
    iVar3 = param_1 + 0x7cc;
    iVar1 = FUN_400da468(iVar3);
    if ((iVar1 == 0) && (iVar1 = FUN_400da468(param_1 + 0x7e4), iVar1 == 0)) {
      FUN_400f0780(0x3ffc5490," status");
      uVar2 = FUN_400f1a9c();
      *(undefined4 *)(param_1 + 0x804) = uVar2;
      FUN_400daf88(param_1);
    }
    else {
      FUN_400f0780(0x3ffc5490,"connect");
      if ((*(byte *)(param_1 + 0x7db) & 0x80) == 0) {
        iVar3 = *(int *)(param_1 + 0x7cc);
      }
      piVar4 = (int *)(param_1 + 0x7e4);
      if ((*(byte *)(param_1 + 0x7f3) & 0x80) == 0) {
        piVar4 = (int *)*piVar4;
      }
      FUN_400f06a4(0x3ffc5490,"uration",iVar3,piVar4);
    }
  }
  return;
}

