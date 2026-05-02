// Function : FUN_4011834c
// Address  : 0x4011834c
// Size     : 330 bytes


void FUN_4011834c(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int *piVar6;
  
  iVar3 = FUN_4010bbc4(0x36,0x20,0x280);
  if (iVar3 != 0) {
    iVar4 = FUN_4010ba9c(iVar3,8);
    if (iVar4 == 0) {
      piVar6 = (int *)0x3f412090;
      if ((*(byte *)(param_1 + 0x94) & 0x10) != 0) {
        piVar6 = (int *)(param_1 + 0x4c);
      }
      puVar5 = *(undefined1 **)(iVar3 + 4);
      puVar5[1] = 0;
      *puVar5 = (char)param_3;
      memw();
      puVar5[8] = *(undefined1 *)(param_2 + 4);
      memw();
      puVar5[9] = *(undefined1 *)(param_2 + 5);
      memw();
      puVar5[10] = *(undefined1 *)(param_2 + 6);
      memw();
      puVar5[0xb] = *(undefined1 *)(param_2 + 7);
      memw();
      puVar5[0xc] = *(undefined1 *)(param_2 + 8);
      memw();
      puVar5[0xd] = *(undefined1 *)(param_2 + 9);
      memw();
      puVar5[0xe] = *(undefined1 *)(param_2 + 10);
      memw();
      puVar5[0xf] = *(undefined1 *)(param_2 + 0xb);
      memw();
      puVar5[0x10] = *(undefined1 *)(param_2 + 0xc);
      memw();
      puVar5[0x11] = *(undefined1 *)(param_2 + 0xd);
      memw();
      puVar5[0x12] = *(undefined1 *)(param_2 + 0xe);
      memw();
      uVar1 = *(undefined1 *)(param_2 + 0xf);
      puVar5[2] = 0;
      puVar5[3] = 0;
      puVar5[4] = 0;
      puVar5[5] = 0;
      puVar5[6] = 0;
      puVar5[7] = 0;
      puVar5[0x13] = uVar1;
      memw();
      puVar5[0x14] = *(undefined1 *)(param_2 + 0x10);
      memw();
      puVar5[0x15] = *(undefined1 *)(param_2 + 0x11);
      memw();
      puVar5[0x16] = *(undefined1 *)(param_2 + 0x12);
      memw();
      puVar5[0x17] = *(undefined1 *)(param_2 + 0x13);
      memw();
      memw();
      uVar2 = FUN_4011dbec(iVar3,0x3a,*(undefined2 *)(iVar3 + 10),piVar6,param_2 + 4);
      puVar5[2] = (char)uVar2;
      puVar5[3] = (char)((ushort)uVar2 >> 8);
      memw();
      memw();
      FUN_40118000(iVar3,0x3a,0);
      if (param_3 == 0x83) {
        *(undefined1 *)(param_2 + 0x18) = 1;
        memw();
      }
      if ((((*piVar6 == 0) && (piVar6[1] == 0)) && (piVar6[2] == 0)) && (piVar6[3] == 0)) {
        piVar6 = (int *)0x0;
      }
      memw();
      FUN_40117f9c(iVar3,piVar6,param_2 + 4,1,0,0,param_1);
    }
    FUN_4010bb10(iVar3);
  }
  return;
}

