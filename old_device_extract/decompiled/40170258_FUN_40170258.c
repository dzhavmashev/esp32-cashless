// Function : FUN_40170258
// Address  : 0x40170258
// Size     : 60 bytes


void FUN_40170258(uint param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *in_t0;
  int in_SCOMPARE1;
  
  piVar3 = (int *)(param_2 + -0x40);
  if (1 < param_1) {
    piVar3 = in_t0;
    FUN_401701a8(*(undefined4 *)(param_2 + -0x24));
  }
  memw();
  iVar4 = *piVar3;
  do {
    iVar5 = iVar4 + -1;
    wsr((char)in_SCOMPARE1,iVar4);
    iVar2 = *piVar3;
    if (iVar2 == in_SCOMPARE1) {
      *piVar3 = iVar5;
    }
    bVar1 = iVar2 != iVar4;
    iVar4 = iVar2;
  } while (bVar1);
  if (iVar5 == 0) {
    if ((code *)piVar3[5] != (code *)0x0) {
      (*(code *)piVar3[5])(param_2 + 0x20);
    }
    FUN_40170898(param_2 + 0x20);
  }
  return;
}

