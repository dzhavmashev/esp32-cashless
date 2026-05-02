// Function : FUN_40116068
// Address  : 0x40116068
// Size     : 235 bytes


void FUN_40116068(int param_1,undefined1 param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 uStack_28;
  undefined4 auStack_24 [9];
  
  iVar2 = FUN_4010bbc4(0x36,0x24,0x280);
  if (iVar2 != 0) {
    iVar3 = iVar2;
    if (*(ushort *)(iVar2 + 10) < 0x24) {
      iVar3 = (*(code *)&SUB_40094c54)("failed\n",0x169,"message","failed\n");
    }
    iVar5 = *(int *)(param_1 + 4);
    puVar4 = *(undefined1 **)(iVar3 + 4);
    puVar4[1] = param_2;
    *puVar4 = 3;
    puVar4[4] = 0;
    puVar4[5] = 0;
    puVar4[6] = 0;
    puVar4[7] = 0;
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(puVar4 + 8,iVar5,0x1c);
    uStack_28 = *(undefined4 *)(iVar5 + 0xc);
    auStack_24[0] = *(undefined4 *)(iVar5 + 0x10);
    memw();
    iVar3 = FUN_401167b0(auStack_24,&uStack_28);
    if (iVar3 != 0) {
      uVar1 = *(undefined2 *)(iVar2 + 10);
      puVar4[2] = 0;
      puVar4[3] = 0;
      memw();
      memw();
      uVar1 = FUN_4011dc60(puVar4,uVar1);
      puVar4[2] = (char)uVar1;
      puVar4[3] = (char)((ushort)uVar1 >> 8);
      memw();
      memw();
      FUN_40116d00(iVar2,0,&uStack_28,0x40,0,1,iVar3);
    }
    FUN_4010bb10(iVar2);
  }
  return;
}

