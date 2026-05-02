// Function : FUN_401439e8
// Address  : 0x401439e8
// Size     : 322 bytes


int FUN_401439e8(uint *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  int iStack_28;
  int aiStack_24 [9];
  
  puVar2 = param_3;
LAB_401439f2:
  memw();
  iVar1 = FUN_40141738(param_1,param_2,&iStack_28,0x31);
  if (iVar1 == 0) {
    uVar5 = *param_1 + iStack_28;
    puVar3 = puVar2;
    do {
      iVar1 = FUN_40141738(param_1,uVar5,aiStack_24,0x30);
      if (iVar1 == 0) {
        pbVar7 = (byte *)*param_1 + aiStack_24[0];
        if (aiStack_24[0] < 1) {
LAB_40143a78:
          iVar1 = -0x23e0;
          goto LAB_40143a0d;
        }
        *puVar3 = (uint)*(byte *)*param_1;
        memw();
        iVar1 = FUN_40141738(param_1,pbVar7,puVar3 + 1,6);
        if (iVar1 != 0) goto LAB_40143a38;
        uVar6 = *param_1;
        puVar3[2] = uVar6;
        pbVar4 = (byte *)(uVar6 + puVar3[1]);
        *param_1 = (uint)pbVar4;
        if ((int)pbVar7 - (int)pbVar4 < 1) goto LAB_40143a78;
        if ((0x1e < *pbVar4) || ((1 << (*pbVar4 & 0x1f) & 0x50581008U) == 0)) {
          iVar1 = -0x23e2;
          goto LAB_40143a0d;
        }
        *param_1 = (uint)(pbVar4 + 1);
        puVar3[3] = (uint)*pbVar4;
        memw();
        iVar1 = FUN_40186734(param_1,pbVar7,puVar3 + 4);
        if (iVar1 != 0) goto LAB_40143a38;
        uVar6 = *param_1;
        puVar3[5] = uVar6;
        pbVar4 = (byte *)(uVar6 + puVar3[4]);
        *param_1 = (uint)pbVar4;
        if (pbVar7 != pbVar4) {
          iVar1 = -0x23e6;
          goto LAB_40143a0d;
        }
        puVar3[6] = 0;
        memw();
      }
      else {
LAB_40143a38:
        iVar1 = iVar1 + -0x2380;
        if (iVar1 != 0) goto LAB_40143a0d;
      }
      if (*param_1 == uVar5) goto LAB_40143afa;
      *(undefined1 *)(puVar3 + 7) = 1;
      memw();
      memw();
      puVar2 = (uint *)FUN_4013ae30(1,0x20);
      puVar3[6] = (uint)puVar2;
      puVar3 = puVar2;
      if (puVar2 == (uint *)0x0) goto LAB_40143a64;
    } while( true );
  }
  iVar1 = iVar1 + -0x2380;
  goto LAB_40143a0d;
LAB_40143afa:
  if (param_2 == uVar5) {
    return 0;
  }
  puVar2 = (uint *)FUN_4013ae30(1,0x20);
  puVar3[6] = (uint)puVar2;
  if (puVar2 == (uint *)0x0) {
    memw();
LAB_40143a64:
    iVar1 = -0x2880;
    memw();
LAB_40143a0d:
    uVar5 = param_3[6];
    while (uVar5 != 0) {
      uVar6 = *(uint *)(uVar5 + 0x18);
      FUN_4013ae54(uVar5,0x20);
      FUN_4013ae44(uVar5);
      uVar5 = uVar6;
    }
    FUN_4013ae54(param_3,0x20);
    return iVar1;
  }
  goto LAB_401439f2;
}

