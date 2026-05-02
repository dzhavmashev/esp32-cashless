// Function : FUN_4014bbe4
// Address  : 0x4014bbe4
// Size     : 181 bytes


/* WARNING: Removing unreachable block (ram,0x4014bc76) */
/* WARNING: Removing unreachable block (ram,0x4014bc7f) */

undefined4 FUN_4014bbe4(int *param_1,char *param_2)

{
  char cVar1;
  byte bVar2;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    cVar1 = *(char *)(*param_1 + 0x167);
    (*(code *)&SUB_4008b530)((int)param_1 + 0x163,0,0x80);
    if (param_2 != (char *)0x0) {
      if (*param_2 == -0x23) {
        param_2 = param_2 + 4;
      }
      if ((param_2[5] & 1U) != 0) {
        bVar2 = *(byte *)((int)param_1 + 0x163);
        if ((bVar2 != 0x7f) && (cVar1 != '\0')) {
          *(byte *)((int)param_1 + 0x163) = bVar2 + 1;
          *(undefined1 *)((int)param_1 + bVar2 + 0x164) = 0;
          memw();
        }
      }
    }
    memw();
    return 0;
  }
  FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0x7a2);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

