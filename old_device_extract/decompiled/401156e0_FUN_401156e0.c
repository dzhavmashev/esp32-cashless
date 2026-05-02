// Function : FUN_401156e0
// Address  : 0x401156e0
// Size     : 264 bytes


char * FUN_401156e0(int *param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
                   char *param_6)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int *piVar6;
  char *pcVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *pcVar10;
  char *in_t0;
  undefined8 uVar11;
  char *pcStack_2c;
  char *pcStack_28;
  int iStack_24;
  
  pcVar7 = &DAT_0000000a;
  pcVar9 = (char *)0x0;
  piVar6 = (int *)&DAT_3ffc6388;
  pcVar3 = (char *)0x0;
  pcVar2 = &DAT_0000000a;
  pcVar10 = &DAT_0000000a;
  pcStack_2c = (char *)0x0;
  pcStack_28 = (char *)0x0;
  iStack_24 = 10;
  pcVar5 = &DAT_0000000a;
  do {
    uVar11 = CONCAT44(pcVar7,piVar6);
    cVar1 = (char)piVar6[5];
    if (((pcVar5 != &DAT_0000000a) || (pcVar4 = pcVar3, cVar1 != '\0')) &&
       (pcVar4 = pcVar5, cVar1 != '\0')) {
      if (((param_1 != (int *)0x0) && (*param_1 == piVar6[1])) &&
         ((param_3 == 0 || (piVar6[2] == param_3)))) {
LAB_401157bc:
        memw();
        return pcVar3;
      }
      param_6 = (char *)(uint)*(ushort *)((int)piVar6 + 0x12);
      if (cVar1 == '\x01') {
        if (*piVar6 == 0) goto LAB_40115774;
        if (pcStack_28 <= param_6) {
          pcStack_28 = param_6;
          uVar11 = CONCAT44(pcVar3,piVar6);
        }
      }
      else if (pcVar9 <= param_6) {
        pcVar2 = pcVar3;
        pcVar9 = param_6;
      }
    }
    while( true ) {
      pcVar7 = (char *)((ulonglong)uVar11 >> 0x20);
      piVar6 = (int *)((int)uVar11 + 0x18);
      pcVar3 = (char *)(int)(short)((short)pcVar3 + 1);
      iStack_24 = iStack_24 + -1;
      pcVar5 = pcVar4;
      if (iStack_24 != 0) break;
      if ((param_2 & 2) != 0) {
LAB_4011579c:
        pcVar3 = (char *)0xffffffff;
        goto LAB_401157bc;
      }
      pcVar3 = pcVar4;
      if (pcVar4 == &DAT_0000000a) {
        if ((param_2 & 1) == 0) goto LAB_4011579c;
        if (pcVar2 == &DAT_0000000a) {
          if ((pcVar10 == &DAT_0000000a) && (pcVar10 = pcVar7, pcVar7 == &DAT_0000000a))
          goto LAB_4011579c;
LAB_401157c6:
          FUN_40115680(pcVar10);
          pcVar3 = pcVar10;
          goto LAB_401157cd;
        }
        param_2 = *(uint *)(&DAT_3ffc6388 + (int)pcVar2 * 0x18);
        pcVar10 = pcVar2;
        if (param_2 == 0) goto LAB_401157c6;
        pcVar10 = "tharp.c";
        uVar8 = 0x17d;
        pcVar3 = in_t0;
      }
      else {
LAB_401157cd:
        pcVar2 = (char *)((int)pcVar3 * 2);
        param_2 = 0;
        param_6 = (char *)(uint)(byte)(&DAT_3ffc639c)[(int)pcVar3 * 0x18];
        if (param_6 == (char *)0x0) {
          if (param_1 != (int *)0x0) {
            *(int *)(&DAT_3ffc638c + (int)pcVar3 * 0x18) = *param_1;
          }
          *(undefined2 *)(&DAT_3ffc639a + (int)pcVar3 * 0x18) = 0;
          memw();
          *(int *)(&DAT_3ffc6390 + (int)pcVar3 * 0x18) = param_3;
          goto LAB_401157bc;
        }
        pcVar10 = "== NULL";
        uVar8 = 0x195;
        pcVar3 = in_t0;
      }
      pcVar9 = "p_entry";
      memw();
      uVar11 = (*(code *)&SUB_40094c54)("!= NULL",uVar8);
      pcVar5 = pcVar3;
      in_t0 = pcVar3;
LAB_40115774:
      pcVar4 = pcVar5;
      if (pcStack_2c <= param_6) {
        memw();
        pcVar10 = pcVar3;
        pcStack_2c = param_6;
      }
    }
  } while( true );
}

