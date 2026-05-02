// Function : FUN_4011a36c
// Address  : 0x4011a36c
// Size     : 109 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4011a36c(int *param_1)

{
  char cVar1;
  int iVar2;
  
  if ((((_DAT_3ffc84a4 == 0) || (_DAT_3ffc8490 != *param_1)) || (_DAT_3ffc8494 != param_1[1])) ||
     (((DAT_3ffc84a0 != (char)param_1[4] || ((*(byte *)(_DAT_3ffc84a4 + 0xeb) & 1) == 0)) ||
      (iVar2 = _DAT_3ffc84a4, (*(byte *)(_DAT_3ffc84a4 + 0xeb) & 4) == 0)))) {
    cVar1 = FUN_40118df8(0);
    if (cVar1 < 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(&DAT_3ffc846c + cVar1 * 0xc);
      if (iVar2 == 0) {
        (*(code *)&SUB_40094c54)("p6_frag",0x6f8,"p_entry","ifetime");
      }
      iVar2 = *(int *)(iVar2 + 0x14);
    }
  }
  return iVar2;
}

