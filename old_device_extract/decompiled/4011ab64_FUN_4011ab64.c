// Function : FUN_4011ab64
// Address  : 0x4011ab64
// Size     : 313 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011ab64(undefined1 *param_1,uint param_2,undefined1 *param_3,undefined2 param_4)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined1 *puVar4;
  int iVar5;
  int aiStack_8c [4];
  undefined1 auStack_7c [88];
  undefined1 *puStack_24;
  
  puVar4 = (undefined1 *)(param_2 & 0xffff);
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  iVar5 = 0x3ffc64d0;
  if ((param_1 != (undefined1 *)0x0) && (param_1[0x14] == '\x06')) {
    memw();
    (*(code *)&SUB_4008b3d0)(0x3ffc64d0,param_1,0x10);
    (*(code *)&SUB_4008b3d0)(0x3ffc64e0,param_3,0x10);
    uVar3 = (undefined2)param_2;
    iVar5 = 0x3ffc64d0;
    goto LAB_4011aba6;
  }
  while( true ) {
    uVar3 = SUB42(puVar4,0);
    (*(code *)&SUB_4008b530)(iVar5,0,10);
    *(undefined1 *)(iVar5 + 10) = 0xff;
    *(undefined1 *)(iVar5 + 0xb) = 0xff;
    memw();
    DAT_3ffc64dc = *param_1;
    DAT_3ffc64dd = param_1[1];
    memw();
    DAT_3ffc64de = param_1[2];
    memw();
    DAT_3ffc64df = param_1[3];
    memw();
    memw();
    memw();
    (*(code *)&SUB_4008b530)(0x3ffc64e0,0,10);
    *(undefined1 *)(iVar5 + 0x1a) = 0xff;
    *(undefined1 *)(iVar5 + 0x1b) = 0xff;
    memw();
    DAT_3ffc64ec = *param_3;
    DAT_3ffc64ed = param_3[1];
    memw();
    DAT_3ffc64ee = param_3[2];
    memw();
    DAT_3ffc64ef = param_3[3];
    memw();
    memw();
LAB_4011aba6:
    *(char *)(iVar5 + 0x20) = (char)((ushort)uVar3 >> 8);
    *(char *)(iVar5 + 0x21) = (char)uVar3;
    *(char *)(iVar5 + 0x22) = (char)((ushort)param_4 >> 8);
    *(char *)(iVar5 + 0x23) = (char)param_4;
    memw();
    memw();
    (*(code *)&SUB_4005da7c)(auStack_7c);
    (*(code *)&SUB_4005da9c)(auStack_7c,iVar5,0x40);
    (*(code *)&SUB_4005db1c)(aiStack_8c,auStack_7c);
    iVar2 = aiStack_8c[0];
    iVar1 = _DAT_3ffc64cc;
    memw();
    iVar5 = FUN_4011b010();
    param_3 = puStack_24;
    puVar4 = _DAT_3ffc5708;
    iVar5 = iVar5 * 0xfa;
    param_1 = (undefined1 *)(iVar5 + iVar2 + iVar1);
    memw();
    memw();
    if (puStack_24 == _DAT_3ffc5708) break;
    (*(code *)&SUB_40082ec4)();
    param_4 = 0x5708;
  }
  return;
}

