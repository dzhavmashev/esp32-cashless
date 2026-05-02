// Function : FUN_4010d33c
// Address  : 0x4010d33c
// Size     : 188 bytes


void FUN_4010d33c(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  if (param_2 != 0) goto LAB_4010d354;
  pcVar4 = " dst_ip";
  uVar3 = 0x8e4;
  do {
    while( true ) {
      (*(code *)&SUB_40094c54)(" LISTEN",uVar3,"ext_iss",pcVar4);
LAB_4010d354:
      if (param_1 != (int *)0x0) break;
      pcVar4 = "lid pcb";
      uVar3 = 0x8e5;
    }
    iVar1 = *param_1;
    if (*param_1 == param_2) {
      *param_1 = *(int *)(param_2 + 0x34);
    }
    else {
      do {
        iVar2 = iVar1;
        if (iVar2 == 0) goto LAB_4010d36d;
        iVar1 = *(int *)(iVar2 + 0x34);
      } while (*(int *)(iVar2 + 0x34) != param_2);
      *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(param_2 + 0x34);
      memw();
    }
LAB_4010d36d:
    *(undefined4 *)(param_2 + 0x34) = 0;
    memw();
    FUN_4010d2e0(param_2);
    if ((*(int *)(param_2 + 0x3c) == 10) || (*(int *)(param_2 + 0x3c) == 1)) {
LAB_4010d3c1:
      if (*(int *)(param_2 + 0x3c) == 1) {
LAB_4010d3c6:
        *(undefined4 *)(param_2 + 0x3c) = 0;
        *(undefined2 *)(param_2 + 0x42) = 0;
        memw();
        memw();
        return;
      }
    }
    else if ((*(ushort *)(param_2 + 0x46) & 1) != 0) {
      *(ushort *)(param_2 + 0x46) = *(ushort *)(param_2 + 0x46) | 2;
      memw();
      memw();
      FUN_40112a70(param_2);
      goto LAB_4010d3c1;
    }
    param_1 = *(int **)(param_2 + 0x98);
    if (param_1 == (int *)0x0) {
      param_1 = *(int **)(param_2 + 0x9c);
      if (param_1 == (int *)0x0) {
        param_1 = *(int **)(param_2 + 0xa0);
        if (param_1 == (int *)0x0) goto LAB_4010d3c6;
        pcVar4 = "leaking";
        uVar3 = 0x8f7;
      }
      else {
        pcVar4 = "leaking";
        uVar3 = 0x8f5;
      }
    }
    else {
      pcVar4 = "pcblist";
      uVar3 = 0x8f4;
    }
  } while( true );
}

