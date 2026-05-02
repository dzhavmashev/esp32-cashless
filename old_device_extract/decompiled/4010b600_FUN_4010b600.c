// Function : FUN_4010b600
// Address  : 0x4010b600
// Size     : 191 bytes


char FUN_4010b600(int param_1,int param_2)

{
  bool bVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  char *pcVar8;
  
  if (param_1 != 0) goto LAB_4010b618;
  pcVar8 = " is 255";
  uVar7 = 0x466;
  while( true ) {
    while( true ) {
      (*(code *)&SUB_40094c54)("d netif",uVar7,"if_poll",pcVar8);
LAB_4010b618:
      if (param_2 != 0) break;
      pcVar8 = "d netif";
      uVar7 = 0x467;
    }
    piVar4 = (int *)FUN_4010bbc4(0xe,*(undefined2 *)(param_2 + 8),0x280);
    if (piVar4 == (int *)0x0) {
      return -1;
    }
    iVar5 = FUN_40185360();
    iVar5 = (uint)*(ushort *)(param_1 + 0x104) + iVar5;
    if (8 < iVar5) {
      FUN_4010bb10(piVar4);
      return -1;
    }
    *(short *)(param_1 + 0x104) = (short)iVar5;
    memw();
    memw();
    cVar3 = FUN_4010bf9c(piVar4,param_2);
    piVar2 = piVar4;
    if (cVar3 != '\0') {
      FUN_4010bb10(piVar4);
      return cVar3;
    }
    do {
      piVar6 = piVar2;
      piVar2 = (int *)*piVar6;
    } while ((int *)*piVar6 != (int *)0x0);
    FUN_4011b020();
    if (*(int *)(param_1 + 0xfc) == 0) break;
    if (*(int **)(param_1 + 0x100) != (int *)0x0) {
      **(int **)(param_1 + 0x100) = (int)piVar4;
      *(int **)(param_1 + 0x100) = piVar6;
      bVar1 = false;
LAB_4010b6a4:
      memw();
      FUN_4011b040();
      if (bVar1) {
        FUN_40109db4(0x4010b0a0,param_1);
      }
      return '\0';
    }
    pcVar8 = "id pbuf";
    uVar7 = 0x492;
    param_2 = 0;
  }
  *(int **)(param_1 + 0xfc) = piVar4;
  bVar1 = true;
  *(int **)(param_1 + 0x100) = piVar6;
  memw();
  goto LAB_4010b6a4;
}

