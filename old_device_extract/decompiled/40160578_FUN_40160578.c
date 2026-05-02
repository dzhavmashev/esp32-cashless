// Function : FUN_40160578
// Address  : 0x40160578
// Size     : 154 bytes


void FUN_40160578(int *param_1)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  
  if (*(char *)((int)param_1 + 0x12) != '\x06') {
    memw();
    FUN_40147fe4(6,0x800,1," %s %u\n",&PTR_DAT_3f4243a8,"equence",0x2d4);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(undefined1 *)((int)param_1 + 0x12) = 0;
  memw();
  iVar1 = *param_1;
  *param_1 = 0;
  puVar2 = *(uint **)(iVar1 + 0x2c);
  if ((*puVar2 & 0x200000) != 0) {
    memw();
    FUN_40163050(puVar2[4] >> 0x14 & 0xf,*(char *)((int)puVar2 + 5) + '\x02');
    FUN_40188f54(*(uint *)(*(int *)(iVar1 + 0x2c) + 0x10) >> 0x14 & 0xf);
    return;
  }
  if ((*puVar2 & 0x400000) != 0) {
    FUN_40163c48(iVar1,1);
    return;
  }
  if (*(byte *)((int)puVar2 + 6) < DAT_3ffbfff5) {
    uVar3 = 3;
    if (*(byte *)((int)puVar2 + 7) < DAT_3ffbfff4) {
      uVar3 = 4;
    }
  }
  else {
    uVar3 = 2;
  }
  FUN_401603f4(param_1,iVar1,uVar3,1);
  return;
}

