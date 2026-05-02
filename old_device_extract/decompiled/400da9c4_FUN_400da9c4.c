// Function : FUN_400da9c4
// Address  : 0x400da9c4
// Size     : 71 bytes


void FUN_400da9c4(int param_1,short param_2)

{
  int iVar1;
  short *psVar2;
  short *psVar3;
  
  psVar3 = *(short **)(param_1 + 0x830);
  do {
    psVar2 = psVar3;
    if (*(short **)(param_1 + 0x834) == psVar2) {
      return;
    }
    psVar3 = psVar2 + 0xc;
  } while (*psVar2 != param_2);
  iVar1 = FUN_400f1a9c();
  psVar3 = psVar2 + 2;
  if ((*(byte *)((int)psVar2 + 0x13) & 0x80) == 0) {
    psVar3 = *(short **)(psVar2 + 2);
  }
  FUN_400f06a4(0x3ffc5490,"bytes)\n",psVar3,param_2,iVar1 - *(int *)(psVar2 + 10));
  FUN_400da974(param_1 + 0x830,psVar2);
  return;
}

