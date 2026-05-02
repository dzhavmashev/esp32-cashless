// Function : FUN_401147a4
// Address  : 0x401147a4
// Size     : 427 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_401147a4(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint in_t0;
  ushort auStack_22 [17];
  
  if (param_1 == 0) {
    uVar1 = 0xf0;
  }
  else {
    iVar5 = *(int *)(param_1 + 200);
    if (iVar5 == 0) {
      uVar1 = 0xfa;
    }
    else {
      FUN_4018541c(iVar5,1);
      iVar2 = FUN_40114430(param_1,iVar5,3,auStack_22);
      if (iVar2 == 0) {
        uVar1 = 0xff;
      }
      else {
        iVar7 = *(int *)(iVar2 + 4);
        iVar6 = iVar7 + 0xf0;
        uVar3 = FUN_401142d4(auStack_22[0],iVar6,0x39,2);
        auStack_22[0] = (ushort)uVar3;
        memw();
        memw();
        uVar3 = FUN_40114298(uVar3,iVar6,*(undefined2 *)(param_1 + 0xe0));
        auStack_22[0] = (ushort)uVar3;
        memw();
        memw();
        uVar3 = FUN_401142d4(uVar3,iVar6,0x32,4);
        auStack_22[0] = (ushort)uVar3;
        memw();
        memw();
        uVar4 = FUN_40109eec(*(undefined4 *)(iVar5 + 0x3c));
        uVar3 = FUN_40114328(uVar3,iVar6,uVar4);
        auStack_22[0] = (ushort)uVar3;
        memw();
        memw();
        uVar3 = FUN_401145e4(param_1,iVar7,uVar3);
        auStack_22[0] = (ushort)uVar3;
        memw();
        memw();
        uVar3 = FUN_401142d4(uVar3,iVar6,0x36,4);
        auStack_22[0] = (ushort)uVar3;
        memw();
        memw();
        uVar4 = FUN_40109eec(*(undefined4 *)(iVar5 + 0x24));
        uVar3 = FUN_40114328(uVar3,iVar6,uVar4);
        auStack_22[0] = (ushort)uVar3;
        memw();
        memw();
        auStack_22[0] = FUN_401142d4(uVar3,iVar6,0x37,5);
        memw();
        uVar8 = (uint)auStack_22[0];
        if (0x7f < uVar8) {
          memw();
          uVar8 = in_t0;
          FUN_40114310();
        }
        *(char *)(iVar6 + uVar8) = 'a';
        auStack_22[0] = (ushort)(uVar8 + 1);
        memw();
        memw();
        uVar3 = FUN_40114568(uVar8 + 1 & 0xffff,iVar6,param_1);
        auStack_22[0] = (ushort)uVar3;
        memw();
        memw();
        FUN_40114068(uVar3,iVar6,iVar2);
        uVar1 = FUN_4011397c(_DAT_3ffc6380,iVar2,"dr_aton",0x43,param_1,&DAT_3f411ef4);
        FUN_4010bb10(iVar2);
      }
      if (*(char *)(iVar5 + 6) != -1) {
        *(char *)(iVar5 + 6) = *(char *)(iVar5 + 6) + '\x01';
        memw();
      }
      uVar8 = 4000;
      if (*(byte *)(iVar5 + 6) < 5) {
        uVar8 = (1 << 0x20 - (0x20 - (*(byte *)(iVar5 + 6) & 0x1f))) * 0xfa & 0xffff;
      }
      *(short *)(iVar5 + 10) = (short)((uVar8 + 499) / 500);
      memw();
      if (*(char *)(iVar5 + 8) == '\0') {
        memw();
        FUN_40113258(500,&DAT_40115654,param_1);
        *(undefined1 *)(iVar5 + 8) = 1;
        memw();
      }
    }
  }
  memw();
  return uVar1;
}

