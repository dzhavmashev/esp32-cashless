// Function : FUN_401100f0
// Address  : 0x401100f0
// Size     : 260 bytes


int FUN_401100f0(undefined4 param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
                undefined2 param_6,byte param_7,undefined2 param_8)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int in_t0;
  
  memw();
  iVar2 = FUN_4010bbc4(0x36,param_2 + param_3 + 0x14 & 0xffff,0x280);
  if (iVar2 != 0) {
    if ((int)(uint)*(ushort *)(iVar2 + 10) <= (int)(param_2 + 0x13)) {
      iVar2 = in_t0;
      (*(code *)&SUB_40094c54)("lid pcb",0x724,"options"," optlen");
    }
    puVar4 = *(undefined1 **)(iVar2 + 4);
    memw();
    uVar1 = FUN_40185288(param_5);
    *puVar4 = (char)uVar1;
    puVar4[1] = (char)((ushort)uVar1 >> 8);
    memw();
    memw();
    uVar1 = FUN_40185288(param_6);
    puVar4[2] = (char)uVar1;
    puVar4[5] = (char)((uint)param_4 >> 8);
    puVar4[7] = (char)((uint)param_4 >> 0x18);
    puVar4[3] = (char)((ushort)uVar1 >> 8);
    puVar4[4] = (char)param_4;
    puVar4[6] = (char)((uint)param_4 >> 0x10);
    memw();
    memw();
    uVar3 = FUN_40109eec(param_1);
    puVar4[8] = (char)uVar3;
    puVar4[9] = (char)((uint)uVar3 >> 8);
    puVar4[0xb] = (char)((uint)uVar3 >> 0x18);
    puVar4[10] = (char)((uint)uVar3 >> 0x10);
    memw();
    memw();
    uVar1 = FUN_40185288(((param_2 >> 2) + 5) * 0x1000 & 0xffff | (uint)param_7);
    puVar4[0xc] = (char)uVar1;
    puVar4[0xd] = (char)((ushort)uVar1 >> 8);
    memw();
    memw();
    uVar1 = FUN_40185288(param_8);
    puVar4[0xe] = (char)uVar1;
    memw();
    puVar4[0xf] = (char)((ushort)uVar1 >> 8);
    puVar4[0x10] = 0;
    puVar4[0x11] = 0;
    puVar4[0x12] = 0;
    puVar4[0x13] = 0;
    memw();
  }
  memw();
  return iVar2;
}

