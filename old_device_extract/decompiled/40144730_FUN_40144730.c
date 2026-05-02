// Function : FUN_40144730
// Address  : 0x40144730
// Size     : 255 bytes


void FUN_40144730(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = param_1;
  if (param_1 != (int *)0x0) {
    do {
      FUN_40139b44(piVar4 + 0x33);
      FUN_4013ae44(piVar4[0x54]);
      iVar3 = piVar4[0x1a];
      while (iVar3 != 0) {
        iVar5 = *(int *)(iVar3 + 0x18);
        memw();
        FUN_4013ae54(iVar3,0x20);
        FUN_4013ae44(iVar3);
        iVar3 = iVar5;
      }
      iVar3 = piVar4[0x22];
      while (iVar3 != 0) {
        iVar5 = *(int *)(iVar3 + 0x18);
        memw();
        FUN_4013ae54(iVar3,0x20);
        FUN_4013ae44(iVar3);
        iVar3 = iVar5;
      }
      iVar3 = piVar4[0x4d];
      while (iVar3 != 0) {
        iVar5 = *(int *)(iVar3 + 0xc);
        memw();
        FUN_4013ae54(iVar3,0x10);
        FUN_4013ae44(iVar3);
        iVar3 = iVar5;
      }
      iVar3 = piVar4[0x41];
      while (iVar3 != 0) {
        iVar5 = *(int *)(iVar3 + 0xc);
        memw();
        FUN_4013ae54(iVar3,0x10);
        FUN_4013ae44(iVar3);
        iVar3 = iVar5;
      }
      iVar3 = piVar4[0x45];
      while (iVar3 != 0) {
        iVar5 = *(int *)(iVar3 + 0xc);
        memw();
        FUN_4013ae54(iVar3,0x10);
        FUN_4013ae44(iVar3);
        iVar3 = iVar5;
      }
      if ((piVar4[3] != 0) && (*piVar4 != 0)) {
        FUN_4013ae54(piVar4[3],piVar4[2]);
        FUN_4013ae44(piVar4[3]);
      }
      piVar1 = piVar4 + 0x55;
      piVar2 = param_1;
      piVar4 = (int *)*piVar1;
    } while ((int *)*piVar1 != (int *)0x0);
    do {
      piVar4 = (int *)piVar2[0x55];
      FUN_4013ae54(piVar2,0x158);
      if (param_1 != piVar2) {
        FUN_4013ae44(piVar2);
      }
      piVar2 = piVar4;
    } while (piVar4 != (int *)0x0);
  }
  return;
}

