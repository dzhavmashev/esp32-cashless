// Function : FUN_4015f1dc
// Address  : 0x4015f1dc
// Size     : 228 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015f1dc(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  undefined4 auStack_28 [10];
  
  uVar3 = *(uint *)(param_2 + 0x98) + 1;
  uStack_30 = 0;
  memw();
  uVar4 = (uint)(uVar3 < *(uint *)(param_2 + 0x98)) + *(int *)(param_2 + 0x9c);
  iVar1 = *(int *)(param_1 + 4);
  *(uint *)(param_2 + 0x98) = uVar3;
  *(uint *)(param_2 + 0x9c) = uVar4;
  uVar2 = *(undefined4 *)(iVar1 + 4);
  if (uVar3 == 0 && uVar4 == 0) {
    uStack_2c = 0x100;
    memw();
  }
  else {
    uStack_2c = CONCAT11((char)uVar3,(char)(uVar3 >> 8));
    uStack_30 = (uVar4 & 0xff) << 8;
    uStack_30 = CONCAT13((char)(uVar3 >> 0x10),CONCAT12((char)(uVar3 >> 0x18),(undefined2)uStack_30)
                        );
    uStack_30 = CONCAT31(uStack_30._1_3_,(char)(uVar4 >> 8));
    memw();
    memw();
  }
  memw();
  iVar1 = (*_DAT_3ffc8ad0)(param_2 + 0xa8,uVar2,
                           (uint)*(ushort *)(param_1 + 0x16) + (uint)*(ushort *)(param_1 + 0x14),
                           0x18,&uStack_30,0,auStack_28);
  if (iVar1 == 0) {
    FUN_40147fe4(1,0x40,1,"");
  }
  else {
    (*(code *)&SUB_4008b3d0)(uVar2,iVar1,auStack_28[0]);
    (**(code **)(_DAT_3ffc1a34 + 0xb0))(iVar1);
    *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + 0x10;
    memw();
    *(uint *)(*(int *)(param_1 + 0x2c) + 0x10) =
         *(uint *)(*(int *)(param_1 + 0x2c) + 0x10) & 0xfffff0ff;
    **(uint **)(param_1 + 0x2c) = **(uint **)(param_1 + 0x2c) & 0xfffffffe;
    *(undefined1 *)(*(int *)(param_1 + 0x2c) + 0x10) = 0xc0;
    memw();
  }
  memw();
  return 0;
}

