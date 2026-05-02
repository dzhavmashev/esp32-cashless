// Function : FUN_401143bc
// Address  : 0x401143bc
// Size     : 113 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401143bc(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = _DAT_3ffc6380;
  if (DAT_3ffc637c == '\0') {
    if (_DAT_3ffc6380 != 0) {
      (*(code *)&SUB_40094c54)("ONS_LEN",0x11f,"cp_recv","t error");
    }
    iVar2 = FUN_40113f2c();
    uVar3 = 0xff;
    _DAT_3ffc6380 = iVar2;
    if (iVar2 == 0) goto LAB_40114428;
    *(byte *)(iVar2 + 0x31) = *(byte *)(iVar2 + 0x31) | 0x20;
    memw();
    memw();
    FUN_40113770(iVar2,&DAT_3f411ef4,0x44);
    FUN_40113d60(_DAT_3ffc6380,&DAT_3f411ef4,0x43);
    FUN_40185408(_DAT_3ffc6380,0x40114a94,iVar1);
  }
  uVar3 = 0;
  DAT_3ffc637c = DAT_3ffc637c + '\x01';
  memw();
LAB_40114428:
  memw();
  return uVar3;
}

