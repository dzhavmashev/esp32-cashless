// Function : FUN_400daa6c
// Address  : 0x400daa6c
// Size     : 685 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400daa6c(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 ****ppppuVar8;
  int aiStack_44 [2];
  code *pcStack_3c;
  undefined1 *puStack_38;
  undefined4 ***local_34 [2];
  code *pcStack_2c;
  undefined1 *puStack_28;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar3 = param_1 + 0x7cc;
  FUN_400f0d18(iVar3,param_2);
  *(undefined4 *)(param_1 + 0x7dc) = *(undefined4 *)(param_2 + 0x10);
  *(undefined1 *)(param_1 + 0x7e0) = *(undefined1 *)(param_2 + 0x14);
  iVar5 = param_1 + 0x7e4;
  FUN_400f0d18(iVar5,param_2 + 0x18);
  *(undefined4 *)(param_1 + 0x7f4) = *(undefined4 *)(param_2 + 0x28);
  *(undefined4 *)(param_1 + 0x7f8) = *(undefined4 *)(param_2 + 0x2c);
  *(undefined1 *)(param_1 + 0x7fc) = *(undefined1 *)(param_2 + 0x30);
  iVar1 = FUN_400da468(iVar5);
  if ((iVar1 != 0) && (iVar1 = FUN_400e6a84(0x3ffc4d78), iVar1 != 0)) {
    FUN_400e6d7c(local_34,0x3ffc4d78);
    iVar1 = FUN_400da468(local_34);
    uVar7 = 0x3ffc5490;
    if (iVar1 != 0) goto LAB_400dad05;
    FUN_400f0d18(iVar5,local_34);
    ppppuVar8 = local_34;
    if (((uint)puStack_28 & 0x80000000) == 0) {
      ppppuVar8 = (undefined4 ****)local_34[0];
    }
    FUN_400f06a4(0x3ffc5490,"or mTLS",ppppuVar8);
    uVar7 = 0x3ffc5490;
    while( true ) {
      FUN_400f0a50(local_34);
      uVar2 = 0;
LAB_400dacf0:
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) break;
      func_0x40082ecc();
LAB_400dad05:
      FUN_400f0780(uVar7,"te: %s\n");
    }
    return uVar2;
  }
  FUN_400f0780(0x3ffc5490,"%lums)\n");
  iVar1 = iVar3;
  if ((*(byte *)(param_1 + 0x7db) & 0x80) == 0) {
    iVar1 = *(int *)(param_1 + 0x7cc);
  }
  FUN_400f06a4(0x3ffc5490,"ul",iVar1,*(undefined4 *)(param_1 + 0x7dc));
  iVar1 = iVar5;
  if ((*(byte *)(param_1 + 0x7f3) & 0x80) == 0) {
    iVar1 = *(int *)(param_1 + 0x7e4);
  }
  FUN_400f06a4(0x3ffc5490,"rt: %d, Device ID: %s\n",iVar1);
  if ((*(byte *)(param_1 + 0x7db) & 0x80) == 0) {
    iVar3 = *(int *)(param_1 + 0x7cc);
  }
  *(int *)(param_1 + 0x88) = iVar3;
  *(undefined1 *)(param_1 + 0x8e) = 0;
  *(undefined2 *)(param_1 + 0x8c) = *(undefined2 *)(param_1 + 0x7dc);
  uVar7 = (uint)*(ushort *)(param_1 + 0x7f4);
  *(uint *)(param_1 + 0x90) = uVar7 * 1000;
  *(undefined1 *)(param_1 + 0x94) = *(undefined1 *)(param_1 + 0x7fc);
  if ((*(byte *)(param_1 + 0x7f3) & 0x80) == 0) {
    iVar5 = *(int *)(param_1 + 0x7e4);
  }
  puStack_38 = (undefined1 *)0x400da768;
  *(int *)(param_1 + 0x7c) = iVar5;
  pcStack_3c = FUN_40183ea8;
  pcStack_2c = (code *)0x0;
  aiStack_44[0] = param_1;
  FUN_40183ea8(local_34,aiStack_44,2);
  puStack_28 = puStack_38;
  pcStack_2c = pcStack_3c;
  FUN_400d73b8(local_34,param_1 + 0xc);
  uVar2 = *(undefined4 *)(param_1 + 0x14);
  *(code **)(param_1 + 0x14) = pcStack_2c;
  uVar6 = *(undefined4 *)(param_1 + 0x18);
  *(undefined1 **)(param_1 + 0x18) = puStack_28;
  pcStack_2c = (code *)uVar2;
  puStack_28 = (undefined1 *)uVar6;
  (*(code *)&LAB_40183a17_1)(local_34);
  (*(code *)&LAB_40183a17_1)(aiStack_44);
  puStack_38 = (undefined1 *)0x400db4a8;
  pcStack_3c = FUN_40183ec0;
  pcStack_2c = (code *)0x0;
  aiStack_44[0] = param_1;
  FUN_40183ec0(local_34,aiStack_44,2);
  puStack_28 = puStack_38;
  pcStack_2c = pcStack_3c;
  FUN_400d73b8(local_34,param_1 + 0x1c);
  uVar2 = *(undefined4 *)(param_1 + 0x24);
  *(code **)(param_1 + 0x24) = pcStack_2c;
  uVar6 = *(undefined4 *)(param_1 + 0x28);
  *(undefined1 **)(param_1 + 0x28) = puStack_28;
  pcStack_2c = (code *)uVar2;
  puStack_28 = (undefined1 *)uVar6;
  (*(code *)&LAB_40183a17_1)(local_34);
  (*(code *)&LAB_40183a17_1)(aiStack_44);
  puStack_38 = &LAB_400da8f8;
  pcStack_3c = FUN_40183ed8;
  pcStack_2c = (code *)0x0;
  aiStack_44[0] = param_1;
  FUN_40183ed8(local_34,aiStack_44,2);
  puStack_28 = puStack_38;
  pcStack_2c = pcStack_3c;
  FUN_400d73b8(local_34,param_1 + 0x4c);
  uVar2 = *(undefined4 *)(param_1 + 0x54);
  *(code **)(param_1 + 0x54) = pcStack_2c;
  uVar6 = *(undefined4 *)(param_1 + 0x58);
  *(undefined1 **)(param_1 + 0x58) = puStack_28;
  pcStack_2c = (code *)uVar2;
  puStack_28 = (undefined1 *)uVar6;
  (*(code *)&LAB_40183a17_1)(local_34);
  (*(code *)&LAB_40183a17_1)(aiStack_44);
  puStack_38 = (undefined1 *)0x400daa04;
  pcStack_3c = FUN_40183ef0;
  pcStack_2c = (code *)0x0;
  aiStack_44[0] = param_1;
  FUN_40183ef0(local_34,aiStack_44,2);
  puStack_28 = puStack_38;
  pcStack_2c = pcStack_3c;
  FUN_400d73b8(local_34,param_1 + 0x5c);
  uVar2 = *(undefined4 *)(param_1 + 100);
  *(code **)(param_1 + 100) = pcStack_2c;
  uVar4 = *(uint *)(param_1 + 0x68);
  *(undefined1 **)(param_1 + 0x68) = puStack_28;
  pcStack_2c = (code *)uVar2;
  puStack_28 = (undefined1 *)uVar4;
  (*(code *)&LAB_40183a17_1)(local_34);
  (*(code *)&LAB_40183a17_1)(aiStack_44);
  uVar2 = 1;
  goto LAB_400dacf0;
}

