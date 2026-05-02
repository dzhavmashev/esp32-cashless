// Function : FUN_40103398
// Address  : 0x40103398
// Size     : 298 bytes


undefined4
FUN_40103398(int param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5,int param_6,
            uint param_7,int param_8)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 uVar6;
  undefined4 uStack_28;
  undefined1 *apuStack_24 [9];
  
  if (param_6 != 0) {
    iVar2 = FUN_40105c8c(*(undefined4 *)(param_1 + 0x1f0));
    iVar3 = 0x5f;
    if (iVar2 == 0x18) {
      iVar3 = 0x67;
    }
    memw();
    iVar3 = FUN_4010544c(param_1,3,0,(param_7 & 0xffff) + iVar3 & 0xffff,&uStack_28,apuStack_24);
    if (iVar3 != 0) {
      uVar6 = 0xfe;
      if (*(int *)(param_1 + 0x240) == 2) {
        uVar6 = 2;
      }
      uVar4 = param_4 & 0xffff | 0x108;
      *apuStack_24[0] = uVar6;
      apuStack_24[0][1] = (char)(uVar4 >> 8);
      apuStack_24[0][2] = (char)uVar4;
      memw();
      if (*(int *)(param_1 + 0x240) == 2) {
        uVar6 = 0;
        apuStack_24[0][3] = 0;
      }
      else {
        uVar6 = *(undefined1 *)(param_3 + 4);
        apuStack_24[0][3] = *(undefined1 *)(param_3 + 3);
        memw();
        memw();
      }
      apuStack_24[0][4] = uVar6;
      memw();
      memw();
      (*(code *)&SUB_4008b3d0)(apuStack_24[0] + 5,param_3 + 5,8);
      uVar6 = (undefined1)((param_7 & 0xffff) >> 8);
      if (iVar2 == 0x18) {
        apuStack_24[0][0x65] = uVar6;
        puVar5 = apuStack_24[0] + 0x67;
        apuStack_24[0][0x66] = (char)param_7;
        memw();
      }
      else {
        apuStack_24[0][0x5d] = uVar6;
        puVar5 = apuStack_24[0] + 0x5f;
        apuStack_24[0][0x5e] = (char)param_7;
        memw();
        memw();
      }
      memw();
      (*(code *)&SUB_4008b3d0)(puVar5,param_6,param_7);
      (*(code *)&SUB_4008b3d0)(apuStack_24[0] + 0xd,param_5,0x20);
      memw();
      FUN_401031a8(param_1,param_8,*(undefined4 *)(param_8 + 0x58),param_4,param_2,0x888e,iVar3,
                   uStack_28,apuStack_24[0] + 0x4d);
      uVar1 = 0;
      FUN_401054b4(iVar3);
      goto LAB_401033a3;
    }
  }
  uVar1 = 0xffffffff;
LAB_401033a3:
  memw();
  return uVar1;
}

