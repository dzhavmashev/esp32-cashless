// Function : FUN_4010b0a8
// Address  : 0x4010b0a8
// Size     : 190 bytes


void FUN_4010b0a8(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  ushort uVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  
  if (param_1 != 0) goto LAB_4010b0c0;
  pcVar7 = "L";
  uVar5 = 0x4d6;
LAB_4010b0b7:
  (*(code *)&SUB_40094c54)("d netif",uVar5,"ddr_set",pcVar7);
LAB_4010b0c0:
  FUN_4011b020();
  do {
    piVar2 = *(int **)(param_1 + 0xfc);
    piVar3 = piVar2;
    uVar4 = 1;
    if (piVar2 == (int *)0x0) {
      FUN_4011b040();
      return;
    }
    while (*(short *)((int)piVar3 + 10) != (short)piVar3[2]) {
      if ((int *)*piVar3 == (int *)0x0) {
        pcVar7 = "netif.c";
        uVar5 = 0x4e2;
        goto LAB_4010b0b7;
      }
      piVar3 = (int *)*piVar3;
      uVar4 = uVar4 + 1 & 0xff;
    }
    if (uVar4 == 0) {
      pcVar7 = "= NULL!";
      uVar5 = 0x4eb;
      goto LAB_4010b0b7;
    }
    *(ushort *)(param_1 + 0x104) = *(short *)(param_1 + 0x104) - uVar4;
    memw();
    if (*(int **)(param_1 + 0x100) == piVar3) {
      *(undefined4 *)(param_1 + 0x100) = 0;
      *(undefined4 *)(param_1 + 0xfc) = 0;
    }
    else {
      iVar6 = *piVar3;
      *(int *)(param_1 + 0xfc) = iVar6;
      if (iVar6 == 0) break;
    }
    *piVar3 = 0;
    memw();
    FUN_4011b040();
    *(char *)((int)piVar2 + 0xf) = *(char *)(param_1 + 0xee) + '\x01';
    memw();
    memw();
    cVar1 = FUN_4010af64(piVar2,param_1);
    if (cVar1 != '\0') {
      FUN_4010bb10(piVar2);
    }
    FUN_4011b020();
  } while( true );
  pcVar7 = "derflow";
  uVar5 = 0x4f6;
  memw();
  goto LAB_4010b0b7;
}

