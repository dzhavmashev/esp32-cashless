// Function : FUN_4015ecb4
// Address  : 0x4015ecb4
// Size     : 169 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015ecb4(int param_1,int param_2,byte *param_3,int param_4)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  code *pcVar6;
  
  if (param_1 == 0) {
    FUN_40147fe4(1,0x800,1,"oc fail",&PTR_s_API_PSK_3f424344,0x144);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((*(byte *)(param_2 + 1) & 0x40) != 0) {
    param_3 = param_3 + _DAT_3ffbfebc;
    param_4 = param_4 - _DAT_3ffbfec0;
  }
  bVar1 = *param_3;
  if (bVar1 == 7) {
    if (param_3[1] == 0) {
      piVar2 = (int *)&DAT_3ffbfe8c;
LAB_4015ed27:
      pcVar6 = (code *)*piVar2;
LAB_4015ed51:
      if (pcVar6 == (code *)0x0) {
        return 0;
      }
      goto LAB_4015ed5c;
    }
  }
  else if (bVar1 < 8) {
    if (bVar1 == 3) {
      uVar5 = (uint)param_3[1];
      iVar3 = 0x3ffbfe90;
      if (uVar5 < 3) goto LAB_4015ed4c;
    }
    else if ((bVar1 == 4) && (uVar5 = (uint)param_3[1], uVar5 < 0x22)) {
      iVar3 = 0x3ffbfdf8;
LAB_4015ed4c:
      pcVar6 = *(code **)(uVar5 * 4 + iVar3);
      goto LAB_4015ed51;
    }
  }
  else {
    if (bVar1 == 8) {
      pcVar6 = FUN_40186ac0;
      if (1 < param_3[1]) goto LAB_4015ed5c;
      pcVar6 = *(code **)((uint)param_3[1] * 4 + 0x3ffbfe80);
      goto LAB_4015ed51;
    }
    if (bVar1 == 0x7f) {
      piVar2 = (int *)&DAT_3ffbfe88;
      goto LAB_4015ed27;
    }
  }
  pcVar6 = FUN_40186ac0;
LAB_4015ed5c:
  uVar4 = (*pcVar6)(param_1,param_2,param_3,param_4);
  return uVar4;
}

