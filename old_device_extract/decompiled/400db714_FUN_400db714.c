// Function : FUN_400db714
// Address  : 0x400db714
// Size     : 693 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400db714(uint param_1,int *param_2,int *param_3,undefined1 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined4 ****ppppuVar5;
  int *piVar6;
  undefined4 ****ppppuVar7;
  undefined1 auStack_c0 [8];
  undefined1 auStack_b8 [24];
  undefined1 auStack_a0 [16];
  undefined4 uStack_90;
  undefined1 *puStack_8c;
  undefined1 auStack_88 [24];
  undefined1 auStack_70 [20];
  undefined4 ***local_5c [3];
  byte bStack_4d;
  undefined4 ***local_4c [3];
  byte bStack_3d;
  undefined2 auStack_3c [2];
  undefined1 auStack_38 [16];
  undefined4 uStack_28;
  int *piStack_24;
  
  memw();
  memw();
  piStack_24 = _DAT_3ffc5708;
  iVar1 = FUN_400da4f0(param_1);
  puVar4 = (undefined2 *)0x3ffc5490;
  if (iVar1 != 0) goto LAB_400db75d;
  FUN_400f0780(0x3ffc5490,"nnected");
  puVar4 = (undefined2 *)0x3ffc5490;
  param_1 = 0;
  while( true ) {
    param_3 = piStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (piStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
    param_4 = &DAT_3ffc5708;
LAB_400db75d:
    FUN_400f0be8(auStack_3c,"LS: %s\n");
    uVar2 = FUN_400f10c0(auStack_3c,param_1 + 0x7e4);
    uVar2 = FUN_400f10f0(uVar2,"ic: %s\n");
    FUN_400f0d4c(local_5c,uVar2);
    FUN_400f0a50(auStack_3c);
    FUN_400d7378(auStack_c0,0xc00,0);
    uStack_90 = FUN_400d4db0(auStack_a0,"unknown event",auStack_b8);
    puStack_8c = auStack_b8;
    FUN_40183db8(param_2,uStack_90,auStack_b8);
    FUN_400d7378(&uStack_90,0x800,0);
    iVar1 = FUN_400d54e4(auStack_88,param_3);
    if (iVar1 == 0) {
      iVar1 = FUN_400d4db0(auStack_a0,"tring: ",auStack_b8);
      if (iVar1 != 0) {
        FUN_400d43ec(iVar1,auStack_70,auStack_b8);
      }
    }
    else {
      FUN_400f06a4(puVar4,"nnected",*(undefined4 *)(iVar1 * 4 + 0x3ffbdb68));
      FUN_400f0be8(auStack_3c,"ON: %s\n");
      uVar2 = FUN_400f10c0(auStack_3c,param_3);
      FUN_400f0768(puVar4,uVar2);
      FUN_400f0a50(auStack_3c);
      iVar1 = FUN_400d4db0(auStack_a0,"tring: ",auStack_b8);
      uVar2 = 0;
      if (iVar1 != 0) {
        uVar2 = FUN_400d4db0(iVar1," an SSL message",auStack_b8);
      }
      FUN_40183db8(param_3,uVar2);
    }
    FUN_400f0be8(local_4c,&DAT_3f42161d);
    FUN_400d5948(auStack_a0,local_4c);
    ppppuVar5 = local_5c;
    if ((bStack_4d & 0x80) == 0) {
      ppppuVar5 = (undefined4 ****)local_5c[0];
    }
    ppppuVar7 = local_4c;
    if ((bStack_3d & 0x80) == 0) {
      ppppuVar7 = (undefined4 ****)local_4c[0];
    }
    iVar1 = FUN_400eb39c(param_1,ppppuVar5,(uint)param_4 & 0xff,0,ppppuVar7);
    if (iVar1 == 0) {
      ppppuVar5 = local_5c;
      if ((bStack_4d & 0x80) == 0) {
        ppppuVar5 = (undefined4 ****)local_5c[0];
      }
      FUN_400f06a4(puVar4,"d: %u)\n",ppppuVar5);
    }
    else {
      piVar6 = param_2;
      if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
        piVar6 = (int *)*param_2;
      }
      FUN_400f06a4(puVar4,"nt_data",piVar6,param_4,iVar1);
      if (0 < (int)param_4) {
        auStack_3c[0] = (undefined2)iVar1;
        FUN_400f0d4c(auStack_38,param_2);
        uStack_28 = FUN_400f1a9c();
        puVar3 = *(undefined2 **)(param_1 + 0x834);
        puVar4 = *(undefined2 **)(param_1 + 0x838);
        if (puVar3 == puVar4) {
          FUN_400db614(param_1 + 0x830,puVar3,auStack_3c);
        }
        else {
          *puVar3 = auStack_3c[0];
          FUN_400f0d04(puVar3 + 2,auStack_38);
          *(undefined4 *)(puVar3 + 10) = uStack_28;
          *(int *)(param_1 + 0x834) = *(int *)(param_1 + 0x834) + 0x18;
        }
        FUN_400f0a50(auStack_38);
      }
    }
    param_1 = (uint)(iVar1 != 0);
    FUN_400f0a50(local_4c);
    FUN_400d73a8(&uStack_90);
    FUN_400d73a8(auStack_c0);
    FUN_400f0a50(local_5c);
  }
  return;
}

