// Function : FUN_401078c8
// Address  : 0x401078c8
// Size     : 273 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_401078c8(uint *param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4,uint *param_5)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  char *pcVar4;
  uint in_t0;
  undefined2 local_40;
  undefined2 uStack_3e;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  if (param_2 != (undefined4 *)0x0) goto LAB_401078f1;
  pcVar4 = "ith %d\n";
  uVar3 = 0x443;
  while( true ) {
    while( true ) {
      memw();
      param_3 = (*(code *)&SUB_40094c54)("!= NULL",uVar3,"udp_raw",pcVar4);
LAB_401078f1:
      if (param_4 != (undefined4 *)0x0) break;
      pcVar4 = "\"";
      uVar3 = 0x444;
    }
    if (param_5 != (uint *)0x0) break;
    pcVar4 = "ckets.c";
    uVar3 = 0x445;
  }
  uVar2 = (uint)*(byte *)(param_2 + 5);
  if (((*param_1 & 8) != 0) && (uVar2 == 0)) {
    param_2[3] = *param_2;
    param_2[2] = 0xffff0000;
    param_2[1] = 0;
    *param_2 = 0;
    *(byte *)(param_2 + 4) = *(byte *)(param_2 + 5);
    *(undefined1 *)(param_2 + 5) = 6;
    memw();
    goto LAB_40107934;
  }
  while( true ) {
    if ((uVar2 == 0x2e) || (uVar2 == 6)) {
LAB_40107934:
      uVar2 = in_t0;
      local_40 = 0xa1c;
      memw();
      memw();
      uStack_3e = FUN_40185288(param_3);
      uStack_3c = 0;
      uStack_38 = *param_2;
      uStack_34 = param_2[1];
      uStack_30 = param_2[2];
      uStack_2c = param_2[3];
      uStack_28 = (uint)*(byte *)(param_2 + 4);
      memw();
    }
    else {
      local_40 = 0x210;
      memw();
      memw();
      uStack_3e = FUN_40185288();
      uStack_3c = *param_2;
      memw();
      memw();
      uStack_38 = 0;
      uStack_34 = 0;
      uVar2 = in_t0;
    }
    uVar3 = 1;
    uVar1 = (uint)(byte)local_40;
    if ((uVar1 <= *param_5) && (uVar3 = 0, uVar1 < *param_5)) {
      *param_5 = uVar1;
    }
    memw();
    (*(code *)&SUB_4008b3d0)(param_4,&local_40,*param_5);
    param_4 = puStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (puStack_24 == _DAT_3ffc5708) break;
    param_3 = (*(code *)&SUB_40082ec4)();
    in_t0 = uVar2;
  }
  return uVar3;
}

