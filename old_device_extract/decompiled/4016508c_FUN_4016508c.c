// Function : FUN_4016508c
// Address  : 0x4016508c
// Size     : 109 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4016508c(uint param_1,int param_2)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if (1 < param_1) {
    FUN_40147fe4(6,0x200,1,"");
    return 0x102;
  }
  if (param_1 == 0) {
    bVar1 = DAT_3ffc89c4 >> 4;
    iVar3 = _DAT_3ffc7d58;
  }
  else {
    bVar1 = DAT_3ffc89c4 >> 5;
    iVar3 = _DAT_3ffc7d5c;
  }
  if (param_2 == 6) {
    *(undefined1 **)(iVar3 + 0x60) = &DAT_3ffc06c4;
    *(undefined1 **)(iVar3 + 0x70) = &DAT_3ffc06b8;
    *(undefined1 **)(iVar3 + 100) = &DAT_3ffc06b8;
    *(undefined1 **)(iVar3 + 0x68) = &DAT_3ffc06c4;
    memw();
  }
  else {
    puVar2 = &DAT_3ffc0484;
    if ((bVar1 & 1) != 0) {
      puVar2 = (undefined1 *)0x3ffc04fc;
    }
    *(undefined1 **)(iVar3 + 0x60) = puVar2;
    *(undefined1 **)(iVar3 + 0x70) = puVar2;
    *(undefined1 **)(iVar3 + 100) = puVar2;
    *(undefined1 **)(iVar3 + 0x68) = puVar2;
  }
  memw();
  return 0;
}

