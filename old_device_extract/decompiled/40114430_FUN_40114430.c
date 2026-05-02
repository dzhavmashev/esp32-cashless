// Function : FUN_40114430
// Address  : 0x40114430
// Size     : 308 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40114430(int param_1,undefined4 *param_2,int param_3,undefined2 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  if (((param_2 == (undefined4 *)0x0) || (param_1 == 0)) ||
     (iVar1 = FUN_4010bbc4(0x4a,0x170,0x280), iVar1 == 0)) {
    iVar1 = 0;
  }
  else {
    if (*(ushort *)(iVar1 + 10) < 0x170) {
      (*(code *)&SUB_40094c54)("ONS_LEN",0x946,"n_short","ry leak");
    }
    if ((param_3 != 3) || (*(char *)((int)param_2 + 5) == '\x03')) {
      if (*(char *)((int)param_2 + 6) == '\0') {
        _DAT_3ffc6378 = (*(code *)&SUB_400842fc)();
      }
      *param_2 = _DAT_3ffc6378;
    }
    puVar3 = *(undefined1 **)(iVar1 + 4);
    memw();
    (*(code *)&SUB_4008b530)(puVar3,0,0x170);
    *puVar3 = 1;
    puVar3[1] = 1;
    memw();
    puVar3[2] = *(undefined1 *)(param_1 + 0xea);
    memw();
    memw();
    uVar2 = FUN_40109eec(*param_2);
    puVar3[5] = (char)((uint)uVar2 >> 8);
    puVar3[4] = (char)uVar2;
    puVar3[6] = (char)((uint)uVar2 >> 0x10);
    puVar3[7] = (char)((uint)uVar2 >> 0x18);
    memw();
    if ((((param_3 - 7U & 0xff) < 2) || (param_3 == 4)) ||
       ((param_3 == 3 && ((byte)(*(char *)((int)param_2 + 5) - 4U) < 2)))) {
      puVar3[0xc] = *(undefined1 *)(param_1 + 4);
      memw();
      puVar3[0xd] = *(undefined1 *)(param_1 + 5);
      memw();
      puVar3[0xe] = *(undefined1 *)(param_1 + 6);
      memw();
      puVar3[0xf] = *(undefined1 *)(param_1 + 7);
      memw();
    }
    puVar3[0x1c] = *(undefined1 *)(param_1 + 0xe4);
    puVar3[0xec] = 99;
    puVar3[0xef] = 99;
    puVar3[0xed] = 0x82;
    puVar3[0xf0] = 0x35;
    puVar3[0xf1] = 1;
    puVar3[0xee] = 0x53;
    puVar3[0xf2] = (char)param_3;
    *param_4 = 3;
    memw();
    memw();
  }
  return iVar1;
}

