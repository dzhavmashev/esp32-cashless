// Function : FUN_40122bfc
// Address  : 0x40122bfc
// Size     : 65 bytes


bool FUN_40122bfc(int param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 4);
  bVar1 = false;
  if ((uVar3 + 0xc0051ff0 < 0x51fe1) && ((uVar3 & 0xf) == 0)) {
    uVar2 = *(uint *)(param_1 + 8);
    if ((uVar2 + 0xc0052000 < 0x52000) && (uVar3 < uVar2)) {
      bVar1 = uVar2 - uVar3 < 0x10001;
    }
    else {
      bVar1 = false;
    }
  }
  return bVar1;
}

